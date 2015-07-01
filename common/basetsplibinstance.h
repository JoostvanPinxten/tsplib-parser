#ifndef BASETSPLIBINSTANCE_H
#define BASETSPLIBINSTANCE_H

#include <tsplibinstance.h>

namespace TSPLIB {

    class BaseInstance : public Instance
    {
    public:
        BaseInstance();
        bool set_name(const std::string &name);
        bool set_coordinate_section(std::map<int, std::vector<double> > coordinates);
    };
}
#endif // BASETSPLIBINSTANCE_H
