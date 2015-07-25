#ifndef TSPLIBINSTANCE_H
#define TSPLIBINSTANCE_H

#include <map>
#include <vector>
#include <string>
#include <tsp.h>

namespace TSPLIB {
    class Instance
    {
    protected:
        std::string name, comment;
        Instance();
        virtual ~Instance();
    public:
        bool set_name(const std::string &_name);
        std::string get_name() const;

        bool set_comment(const std::string &_comment);
        std::string get_comment() const;

        virtual bool set_node_coordinate_section(std::map<int, std::vector<double> > coordinates) = 0;
        virtual std::map<int, std::vector<double> > get_node_coordinate_section() const = 0;

        virtual bool set_node_coordinate_type(TSP::NODE_COORD_TYPE coord_type) = 0;
        virtual TSP::NODE_COORD_TYPE get_node_coordinate_type() const = 0;

        virtual bool set_dimension(unsigned int dimension) = 0;
        virtual unsigned int get_dimension() const = 0;
    };
}
#endif // TSPLIBINSTANCE_H
