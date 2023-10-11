#pragma once

#include <boost/program_options.hpp>
#include <iostream>
#include <vector>
#include <string>

namespace po = boost::program_options;

class Calculator {
private:
    po::options_description descr;
    po::positional_options_description p;
    po::variables_map vm;
    
public:
    Calculator() = delete;
    Calculator(int argc, char **argv);
    
    void get_com_line_params();
};