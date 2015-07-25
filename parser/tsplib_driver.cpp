// $Id: driver.cc 39 2008-08-03 10:07:15Z tb $
/** \file driver.cc Implementation of the TSPLIB::Driver class. */

#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>

#include "tsplib_driver.h"
#include "tsplib_lexer.h"

#include <basetsplibinstance.h>

namespace TSPLIB {

Driver::Driver()
    : trace_scanning(false),
      trace_parsing(false),
      instance(0)
{
}

bool Driver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

    Scanner scanner(&in);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(trace_parsing);
    return (parser.parse() == 0);
}

bool Driver::parse_file(const std::string &filename)
{
    std::ifstream in(filename.c_str());
    if (!in.good()) return false;
    return parse_stream(in, filename);
}

bool Driver::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}

void Driver::error(const class location& l,
           const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void Driver::error(const std::string& m)
{
    std::cerr << m << std::endl;
}

void Driver::set_name(const std::string *name) {
    get_instance().set_name(*name);
}

/**
 * Create an instance of a TSPLIB specification with the given @param type.
 */
TSPLIB::Instance& Driver::create_instance(TSP::TYPE type) {

    switch(type) {
    default:
    case TSP::TYPE::STUB:
        instance = new TSPLIB::BaseInstance(*instance);
        break;

    }
    return *instance;
}

TSPLIB::Instance& Driver::get_instance()
{
    if(!instance) {
        return create_instance(TSP::TYPE::STUB);
    }
    return *instance;
}

} // namespace TSPLIB
