#include "calculator.h"

Calculator::Calculator(int argc, char **argv) {
    descr.add_options()
        ("help", "Read help message")
        ("operation", po::value<std::string>(&operation), "Set operation. Values: sum | sub")
        ("operands", po::value< std::vector<int> >(&v), "Input numbers. From 3 to 5 numbers")
    ;
    
    p.add("operands", -1);
    po::store(po::command_line_parser(argc, argv).
              options(descr).positional(p).
              style(po::command_line_style::unix_style ^ po::command_line_style::allow_short).
              run(), vm);
    po::notify(vm);
}

void Calculator::operator()() {
    verify_input();
    calculate();
    print_result();
}

void Calculator::verify_input() {
    if ( vm.count("help") || vm.empty() ) {
        descr.print(std::cout);
        exit(0);
    }

    if( vm.count("operation") == 0 ) {
        std::cerr << "The option '--operation' is required but missing" << std::endl;
        exit(1);
    }
    if ( vm.count("operation") ) {
        if ( operation != sumName && operation != subName ) {
            std::cerr << "Wrong name of operation." << std::endl;
            exit(1);
        }
    }

    if( vm.count("operands") == 0 ) {
        std::cerr << "The option '--operands' is required but missing" << std::endl;
        exit(1);
    }
    if ( vm.count("operands") ) {
        if ( v.size() < minNum || v.size() > maxNum ) {
            std::cerr << "Wrong number of input numbers." << std::endl;
            exit(1);
        }
    }
}

void Calculator::calculate() {
    if ( operation == sumName ) {
        for (int n : v)
            result += n;
    } else {
        result = v[0];
        for (size_t i=1;
             i<v.size();
             i++) {
            result -= v[i];
        }
    }
}

void Calculator::print_result() {
    std::cout << "Result: "
              << result
              << std::endl;
}

void Calculator::get_com_line_params() {
    std::cout <<  "Operation is: "
                  << operation
                  << std::endl;
    std::cout <<  "Numbers are: ";
        for(int n : v) {
            std::cout << n << ' ';
        }
        std::cout << std::endl;
}

