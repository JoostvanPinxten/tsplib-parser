#include <iostream>
#include "basetsplibinstance.h"

namespace TSPLIB {
    BaseInstance::BaseInstance(const Instance& i)
    {
        if(&i){ // check for null reference... very nasty!
            name = i.get_name();
            comment = i.get_comment();
        }
    }

    bool BaseInstance::set_coordinate_section(std::map<int, std::vector<double> > coordinates)
    {
        return false;
    }
}
