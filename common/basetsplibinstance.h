#ifndef BASETSPLIBINSTANCE_H
#define BASETSPLIBINSTANCE_H

#include <tsplibinstance.h>
#include <map>
#include <vector>


namespace TSPLIB {

    template<typename T>
    using Matrix = std::vector<std::vector<T>>;

    class BaseInstance : public Instance
    {
    protected:
        bool valid_matrix;
        std::map<int, std::vector<double> > coordinates;
        TSP::NODE_COORD_TYPE coord_type;
        TSP::EDGE_WEIGHT_TYPE edge_type;
        TSP::EDGE_WEIGHT_FORMAT edge_weight_format;
        unsigned int dimension;

        Matrix<int> matrix;

    public:
        BaseInstance(const Instance &i); // initialization from another instance

        bool set_node_coordinate_section(std::map<int, std::vector<double> > coordinates);
        std::map<int, std::vector<double> > get_node_coordinate_section() const;

        bool set_node_coordinate_type(TSP::NODE_COORD_TYPE coord_type);
        TSP::NODE_COORD_TYPE get_node_coordinate_type() const;

        bool set_edge_weight_type(TSP::EDGE_WEIGHT_TYPE edge_type);
        TSP::EDGE_WEIGHT_TYPE get_edge_weight_type() const;

        bool set_edge_weights(std::vector<int> weights);

        /**
         * Retrieves a matrix of doubles, size dimension x dimension, to represent the value
         * of the edges between node x and node y: get_edge_weight_matrix()[x][y]
         *
         * notice: 0-based indexing, while TSPLIB uses 1-based indexing!
         *
         * @return matrix of size dimension x dimension
         */
        Matrix<int> get_edge_weight_matrix() const;

        bool set_dimension(unsigned int dimension);
        unsigned int get_dimension() const;

        int distance(unsigned int i, unsigned int j);
    };
}
#endif // BASETSPLIBINSTANCE_H
