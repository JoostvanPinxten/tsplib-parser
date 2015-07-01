#include "basetsplibinstance.h"

namespace TSPLIB {
    BaseInstance::BaseInstance()
    {

    }

    bool BaseInstance::set_name(const std::string &name)
    {
        return false;
    }

    bool BaseInstance::set_coordinate_section(std::map<int, std::vector<double> > coordinates)
    {
        return false;
    }
}
