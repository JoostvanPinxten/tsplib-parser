#include <iostream>
#include "basetsplibinstance.h"

namespace TSPLIB {
    BaseInstance::BaseInstance(const Instance& i) :
        coord_type(TSP::NODE_COORD_TYPE::NONE),
        dimension(0)
    {
        if(&i){ // check for null reference... very nasty!
            name = i.get_name();
            comment = i.get_comment();
        }
    }


    /// requires dimension and coord_type to be set
    bool BaseInstance::set_node_coordinate_section(std::map<int, std::vector<double> > coordinates)
    {
        int nrCoords = 0;
        if(dimension == 0) {
            std::cerr << "Unexpected coords section, first specify the dimension";
            return false;
        }

        if( coord_type == TSP::NODE_COORD_TYPE::TWO_D) {
            nrCoords = 2;
        } else if( coord_type == TSP::NODE_COORD_TYPE::THREE_D) {
            nrCoords = 3;
        } else if( coord_type == TSP::NODE_COORD_TYPE::NONE ) {
            std::cerr << "Unexpected coords section; first specify the coordinate type!";
            return false;
        }

        try {
            for(unsigned int i = 1; i <= dimension; i ++) {
                auto coordinate = coordinates.at(i);
                if(coordinate.size() != nrCoords) {
                    std::cerr << "Coordinates for node " << i << " do not match the specification; expected " << nrCoords << " coordinates." << std::endl;
                    return false;
                }
            }
        } catch(std::out_of_range ex) {
            std::cerr << "No coordinates found for node " << ex.what() << std::endl;
        }

        this->coordinates = coordinates;

        // TODO: validate the coordinates?
        return true;
    }

    std::map<int, std::vector<double> > BaseInstance::get_node_coordinate_section() const
    {
        return coordinates;
    }

    bool BaseInstance::set_node_coordinate_type(TSP::NODE_COORD_TYPE coord_type)
    {
        this->coord_type = coord_type;
        return true;
    }

    TSP::NODE_COORD_TYPE BaseInstance::get_node_coordinate_type() const
    {
        return coord_type;
    }

    bool BaseInstance::set_dimension(unsigned int dimension)
    {
        this->dimension = dimension;
    }

    unsigned int BaseInstance::get_dimension() const
    {
        return this->dimension;
    }

}
