//
// Created by lamp on 06.02.2021.
//

#include <console.hpp>

console::console(const std::string& name)
:_desc(name){
    _desc.add_options()
            ("help,h", "shows allowed options")
            ("input,i", po::value<std::string>(), "sets input file where the values should be taken")
            ("output,o", po::value<std::string>(), "sets output .json file where the data shall be storaged");
}

void console::encode(){
    size_t max_buffer_size = std::thread::hardware_concurrency();
    sync_queue<hasher::key_value_t> values;
    std::vector<std::thread> tasks;
    std::atomic_int tasks_buffer(0);
    for (; !_kvs.empty();) {
        if (values.size() > max_buffer_size){
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        } else {
            values.push(_kvs.pop());
            tasks.emplace_back([this, &values]{
                auto encoded = hasher::encode(values.pop());
                if (encoded.empty()){
                    return false;
                } else {
                    _values.emplace_back(encoded);
                    return true;
                }
            });
        }
    }
    for(auto&& t : tasks){
        t.join();
    }
}

void console::write(const std::string &path) {
    json values;
    std::ifstream in;
    in.open(path);
    if (in.is_open()) {
        std::stringstream ss;
        ss << in.rdbuf();
        values = ss.str().empty() ? json() : json::parse(ss.str());
    }
    in.close();

    std::ofstream out;
    out.open(path, std::ios::out);

    BOOST_LOG_SEV(lg, logging::trivial::info) << "Values num: " << _values.size();

    for (auto &&value : _values) {
        values["Values"].emplace_back(value);
        std::cout << value << "\n";
    }
    out << values;
    out.close();
    BOOST_LOG_SEV(lg, logging::trivial::info) << "Writing done, values are written to" << path << "\n";
    std::cout << "Values are written to " << path << "\n";
}

void console::parse(const std::string &path) {
    std::ifstream input(path);
    if (!input.is_open()) {
        BOOST_LOG_SEV(lg, logging::trivial::error) << "Parse error: couldn't open file";
        throw std::runtime_error{"Parse error: couldn't open file"};
    }
    BOOST_LOG_SEV(lg, logging::trivial::info) << "Parse: file opened";
    std::cout << "File opened, started parsing.....\n";

    typedef boost::tokenizer< boost::escaped_list_separator< char > > tokenizer;

    std::vector<std::string> vector;
    std::string line;
    while (std::getline(input, line)) {
        tokenizer t(line);
        vector.assign(t.begin(), t.end());
        if (vector.size() > 2) { return; }
        _kvs.push(std::make_pair<std::string, std::string>(vector[0].c_str(), vector[1].c_str()));
        BOOST_LOG_SEV(lg, logging::trivial::info) << "Values parsed: " << vector[0] << " | "
                                                  << vector[1];
    }
    if (_kvs.empty()) {
        BOOST_LOG_SEV(lg, logging::trivial::error) << "Parse error: file is empty";
        throw std::runtime_error{"Parse error: file is empty"};
    }
    BOOST_LOG_SEV(lg, logging::trivial::info) << "Parsing done";
    std::cout << "Parsing done\n";
}

void console::initiate() {
    logging::add_file_log(
            keywords::file_name = "logs/log_%5N.log",
            keywords::rotation_size = 10 * 1024 * 1024,
            keywords::time_based_rotation =
                    sinks::file::rotation_at_time_point(0, 0, 0),
            keywords::format = "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");

    srand(time(nullptr));
}

void console::initiate(const po::variables_map & vm) {
    initiate();
    if (vm.count("help")) {
        BOOST_LOG_SEV(lg, logging::trivial::info) << "Help initiated";
        std::cout << "Encodes values in .csv file to sha256\n" << _desc << "\n\nCOPYRIGHT 2021 LAMP\n";
        exit(0);
    }
    if (!vm.count("input")) {
        BOOST_LOG_SEV(lg, logging::trivial::info) << "No input file";
        std::cout << "No input file entered";
        _path = "data/data.csv";
    } else {
        _path = vm["input"].as<std::string>();
    }
    parse(_path);
    //================================ENCODING ==============================
    encode();
    //=======================================================================
    if (vm.count("output")) {
        write(vm["output"].as<std::string>());
    } else {
        write("log_json/log.json");
    }
}