#ifndef TSPLIBINSTANCE_H
#define TSPLIBINSTANCE_H

#include <map>
#include <vector>
#include <string>

namespace TSPLIB {
    class Instance
    {
    public:
        Instance();
        virtual bool set_name(const std::string &name) = 0;
        virtual bool set_coordinate_section(std::map<int, std::vector<double> > coordinates) = 0;
    };
}
#endif // TSPLIBINSTANCE_H
