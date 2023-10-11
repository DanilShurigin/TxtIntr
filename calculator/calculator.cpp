#include <calculator.h>

Calculator::Calculator(int argc, char **argv) {
    descr.add_options()
        ("help,h", "Read help message")
        ("operation,o", po::value<std::string>()->required(), "Set operation")
        ("input-numbers", po::value< std::vector<int> >()->multitoken(), "Input numbers")
    ;
    
    p.add("input-numbers", -1);
    po::store(po::command_line_parser(argc, argv).
              options(descr).positional(p).run(), vm);
    po::notify(vm);
}

void Calculator::get_com_line_params() {
    if(vm.count("operation")) {
        std::cout <<  "Operation is: "
                  << vm["operation"].as<std::string>()
                  << std::endl;
    }
    
    if(vm.count("input-numbers")) {
        std::cout <<  "Numbers are: "
                  << vm["operation"].as< std::vector<int> >()[0]
                  << std::endl;
    }
}