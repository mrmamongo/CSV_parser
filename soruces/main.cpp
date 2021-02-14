#include <console.hpp>
#include <boost/thread.hpp>

int main(int argc, char** argv) {
    console c("Allowed Options");
    po::variables_map vm;
    po::parsed_options parsed = po::command_line_parser(argc, argv).options(c.get_desc()).allow_unregistered().run();
    po::store(parsed, vm);
    po::notify(vm);
    c.initiate(vm);
}


/*
 *
 * 2:Saratov
 * dklfjsal;kfjkl;sajd;lfal;skdf-f139i039iefjekfj2309
 *
 * 2:Saratov1
 * fl;sajklfkjas;dlkfjoasdifu0as9dfj3kl
 *
 * 2:Saratov2
 *
 * fdskjflkjasdlkfjlaskjhdfkjhasdkjhrf2k3jhf308f0000
 *
 *
 */