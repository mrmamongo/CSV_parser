//
// Created by lamp on 06.02.2021.
//

#ifndef PRODUCER_CONSUMER_CONSOLE_HPP
#define PRODUCER_CONSUMER_CONSOLE_HPP

#include <boost/program_options.hpp>
#include <mutex>
#include <condition_variable>
#include <hasher.hpp>
#include <iostream>
#include <sync_queue.hpp>
#include <thread>
#include <future>
#include <vector>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <memory>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
namespace logging = boost::log;
namespace src = boost::log::sources;
typedef src::severity_logger<logging::trivial::severity_level> logger;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace po = boost::program_options;
class console {
private:
     logger lg;
     po::options_description _desc;
     std::string _path;
     sync_queue<hasher::key_value_t> _kvs;
     std::vector<json> _values;
     void parse(const std::string& path);
     void write(const std::string& path);
     void encode();

    inline static void initiate();
public:
    po::options_description& get_desc() { return _desc; }
    void initiate(const po::variables_map&);
    console(const std::string&);
};


#endif //PRODUCER_CONSUMER_CONSOLE_HPP
