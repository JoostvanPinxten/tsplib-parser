// $Id: driver.cc 39 2008-08-03 10:07:15Z tb $
/** \file driver.cc Implementation of the TSPLIB::Driver class. */

#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>

#include "tsplib_driver.h"
#include "tsplib_lexer.h"

#include <basetsplibinstance.h>
#include <tsplibtourinstance.h>
#include <tsplibdummyinstance.h>

#include <parser/exceptions/exceptions.h>

namespace TSPLIB {

Driver::Driver()
    : trace_scanning(false),
      trace_parsing(false),
      instance(new TSPLIB::DummyInstance)
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

/**
 * Create an instance of a TSPLIB specification with the given @param type.
 */
TSPLIB::Instance& Driver::create_instance(TSP::TYPE type) {

    switch(type) {
        case TSP::TYPE::TOUR:
        {
            Instance * old = instance;
            instance = new TSPLIB::TourInstance(*old);
            delete old;
            break;
        }
        case TSP::TYPE::TSP:
        {
            Instance * old = instance;
            instance = new TSPLIB::BaseInstance(*old);
            delete old;
            break;
        }
        case TSP::TYPE::AGTSP:
        case TSP::TYPE::GTSP:
        {
            Instance * old = instance;
            instance = new TSPLIB::GTSPInstance(*old);
            delete old;
            break;
        }
        default:
        {
            throw TSP::PARSER::Unsupported_exception("Type not supported");
        }
    }
    return *instance;
}

TSPLIB::Instance& Driver::get_instance() const
{
    return *instance;
}

BaseInstance &Driver::get_tsp_instance() const
{
    BaseInstance * tsp = dynamic_cast<BaseInstance*>(instance);
    if(!tsp) {
        throw TSP::PARSER::Inconsistent_definition_exception("Please check the information for consistency with the provided type; trying to set data for a traveling salesman problem");
    }
    return *tsp;
}

GTSPInstance &Driver::get_gtsp_instance() const
{
    GTSPInstance * tsp = dynamic_cast<GTSPInstance*>(instance);
    if(!tsp) {
        throw TSP::PARSER::Inconsistent_definition_exception("Please check the information for consistency with the provided type; trying to set data for a generalized traveling salesman problem");
    }
    return *tsp;
}

TourInstance &Driver::get_tour_instance() const
{
    TourInstance * tsp = dynamic_cast<TourInstance*>(instance);
    if(!tsp) {
        throw TSP::PARSER::Inconsistent_definition_exception("Please check the information for consistency with the provided type");
    }
    return *tsp;
}

} // namespace TSPLIB
