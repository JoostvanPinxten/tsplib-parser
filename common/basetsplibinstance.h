#ifndef BASETSPLIBINSTANCE_H
#define BASETSPLIBINSTANCE_H

#include <tsplibinstance.h>
#include <map>
#include <vector>

namespace TSPLIB {

    class BaseInstance : public Instance
    {
    protected:
        std::map<int, std::vector<double> > coordinates;
        TSP::NODE_COORD_TYPE coord_type;
        unsigned int dimension;
    public:
        BaseInstance(const Instance &i); // initialization from another instance

        bool set_node_coordinate_section(std::map<int, std::vector<double> > coordinates);
        std::map<int, std::vector<double> > get_node_coordinate_section() const;

        bool set_node_coordinate_type(TSP::NODE_COORD_TYPE coord_type);
        TSP::NODE_COORD_TYPE get_node_coordinate_type() const;

        bool set_dimension(unsigned int dimension);
        unsigned int get_dimension() const;
    };
}
#endif // BASETSPLIBINSTANCE_H
