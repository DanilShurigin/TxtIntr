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

    static constexpr size_t minNum = 3;
    static constexpr size_t maxNum = 5;

    const std::string sumName = "sum";
    const std::string subName = "sub";

    int result = 0;
    std::vector<int> v;
    std::string operation;

    void verify_input();
    void calculate();
public:
    Calculator() = delete;
    Calculator(int argc, char **argv);
    
    void get_com_line_params();
    void print_result();
    int get_result() { return result; }
    void operator()();
};