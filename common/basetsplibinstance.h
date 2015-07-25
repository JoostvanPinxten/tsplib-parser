#ifndef BASETSPLIBINSTANCE_H
#define BASETSPLIBINSTANCE_H

#include <tsplibinstance.h>

namespace TSPLIB {

    class BaseInstance : public Instance
    {
    public:
        BaseInstance(const Instance &i); // initialization from another instance
        bool set_coordinate_section(std::map<int, std::vector<double> > coordinates);
    };
}
#endif // BASETSPLIBINSTANCE_H
