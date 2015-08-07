#include "tsplibinstance.h"

/**
 * Base interface for all types of TSPLIBInstances.
 */
namespace TSPLIB {
    Instance::Instance(TSP::TYPE type)
        :type(type)
    {

    }

    Instance::~Instance()
    {

    }

    bool Instance::set_name(const std::string &_name)
    {
        name = _name;
        return false;
    }

    std::string Instance::get_name() const {
        return name;
    }

    bool Instance::set_comment(const std::string &_comment) {
        comment = _comment;
        return true;
    }

    std::string Instance::get_comment() const {
        return comment;
    }
}
