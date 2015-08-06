#include "basetsplibinstance.h"
#include <parser/exceptions/exceptions.h>
#include <sstream>
#include <math.h>
#include <cmath>

namespace TSPLIB {
    std::pair<int, int> geo_to_radian(unsigned int x, unsigned int y) {
        auto PI = 3.141592;
        auto deg = std::round(x);
        auto min = x - deg;
        auto latitude = PI * (deg + 5.0 * min / 3.0 ) / 180.0;

        deg = std::round(y);
        min = y - deg;
        auto longitude = PI * (deg + 5.0 * min / 3.0 ) / 180.0;
        return std::make_pair(latitude, longitude);
    }

    BaseInstance::BaseInstance(const Instance& i) :
        valid_matrix(false),
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
        // validate prerequisites
        unsigned int nrCoords {0};
        if(dimension == 0) {
            throw TSP::PARSER::Inconsistent_definition_exception("Unexpected coords section; first specify the dimensionality!");
            return false;
        }

        switch(coord_type) {
        case TSP::NODE_COORD_TYPE::TWO_D:
            nrCoords = 2;
            break;
        case TSP::NODE_COORD_TYPE::THREE_D:
            nrCoords = 3;
            break;
        case TSP::NODE_COORD_TYPE::NONE:
            throw TSP::PARSER::Inconsistent_definition_exception("Unexpected coords section; first specify the coordinate type!");
            return false;
        }

        // validate the entries given in the map
        try {
            for(unsigned int i = 1; i <= dimension; i ++) {
                auto coordinate = coordinates.at(i);
                if(coordinate.size() != nrCoords) {
                    std::ostringstream err;
                    err << "Coordinates for node " << i << " do not match the specification; expected " << nrCoords << " coordinates." << std::endl;

                    throw TSP::PARSER::Inconsistent_definition_exception(err.str());

                    return false;
                }
            }
        } catch(std::out_of_range ex) {
            std::ostringstream err;
            err << "No coordinates found for node: " << ex.what();

            throw TSP::PARSER::Inconsistent_definition_exception(err.str());
        }

        // copy the validated coordinates
        this->coordinates = coordinates;


        // update the edge weight values!
        switch(edge_type) {
            case TSP::EDGE_WEIGHT_TYPE::EUC_2D:
            case TSP::EDGE_WEIGHT_TYPE::EUC_3D:
            case TSP::EDGE_WEIGHT_TYPE::GEO:
                for(unsigned int i = 0 ; i < dimension; i++) {
                    for(unsigned int j = 0; j < dimension ; j++) {
                        matrix[i][j] = distance(i+1, j+1);
                    }
                }
                valid_matrix = true;
                break;
            default:
                valid_matrix = false;
                break;
        }

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

    bool BaseInstance::set_edge_weight_format(TSP::EDGE_WEIGHT_FORMAT edge_format)
    {
        edge_weight_format = edge_format;
        return true;
    }

    bool BaseInstance::set_edge_weight_type(TSP::EDGE_WEIGHT_TYPE edge_type)
    {
        this->edge_type = edge_type;
        switch(edge_type) {
            case TSP::EDGE_WEIGHT_TYPE::EUC_2D:
            case TSP::EDGE_WEIGHT_TYPE::CEIL_2D:
            case TSP::EDGE_WEIGHT_TYPE::MAX_2D:
            case TSP::EDGE_WEIGHT_TYPE::GEO:
            case TSP::EDGE_WEIGHT_TYPE::ATT:
                set_node_coordinate_type(TSP::NODE_COORD_TYPE::TWO_D);
                break;
            case TSP::EDGE_WEIGHT_TYPE::EUC_3D:
            case TSP::EDGE_WEIGHT_TYPE::MAX_3D:
                set_node_coordinate_type(TSP::NODE_COORD_TYPE::TWO_D);
                break;

            case TSP::EDGE_WEIGHT_TYPE::EXPLICIT:
            default:
                // do nothing
                break;
        }

        return true;
    }

    bool BaseInstance::set_edge_weights(std::vector<int> weights) {

        if(edge_type != TSP::EDGE_WEIGHT_TYPE::EXPLICIT) {
            throw TSP::PARSER::Inconsistent_definition_exception("Cannot set edge weights when edge weight type is not explicit");
        }

        switch(edge_weight_format) {
            case TSP::EDGE_WEIGHT_FORMAT::FULL_MATRIX:
                {
                    if(weights.size() != dimension * dimension) {
                        std::ostringstream err;
                        err << "Expected " << dimension * dimension << " integers, but found " << weights.size();
                        throw TSP::PARSER::Inconsistent_definition_exception(err.str());
                    }
                    for(unsigned int i=0; i< dimension; i++) {
                        for(unsigned int j=0; j< dimension; j++) {
                            matrix[i][j] = weights[i*dimension + j];
                        }
                    }
                }
                valid_matrix = true;
                break;
            default:
                throw TSP::PARSER::Unsupported_exception("Unsupported edge weight format for explicit edge weight type");
        }
        return true;
    }

    TSP::EDGE_WEIGHT_TYPE BaseInstance::get_edge_weight_type() const
    {
        return edge_type;
    }

    Matrix<int> BaseInstance::get_edge_weight_matrix() const
    {
        if(valid_matrix) {
            return matrix;
        }
        throw TSP::PARSER::Inconsistent_definition_exception("Unable to determine matrix; check whether all required attributes have been specified");
    }

    bool BaseInstance::set_dimension(unsigned int dimension)
    {
        if(dimension == 0) {
            throw TSP::PARSER::Inconsistent_definition_exception("Dimension must be larger than 0");
        }

        if(this->dimension != 0) {
            throw TSP::PARSER::Inconsistent_definition_exception("Dimension has already been defined");
        }

        this->dimension = dimension;

        matrix.resize(dimension);
        for(unsigned int i = 0; i < dimension; i++) {
            matrix[i].resize(dimension);
        }

        return true;
    }

    unsigned int BaseInstance::get_dimension() const
    {
        return this->dimension;
    }

    int BaseInstance::distance(unsigned int i, unsigned int j)
    {
        switch (edge_type) {
            case TSP::EDGE_WEIGHT_TYPE::EUC_2D:
            {
                auto p_i = coordinates[i];
                auto p_j = coordinates[j];

                auto xd = p_i[0] - p_j[0];
                auto yd = p_i[1] - p_j[1];

                return std::round(std::sqrt(xd*xd + yd*yd));
            }
            case TSP::EDGE_WEIGHT_TYPE::EUC_3D:
            {
                auto p_i = coordinates[i];
                auto p_j = coordinates[j];

                auto xd = p_i[0] - p_j[0];
                auto yd = p_i[1] - p_j[1];
                auto zd = p_i[2] - p_j[2];

                return std::round(std::sqrt(xd*xd + yd*yd + zd*zd));
            }
            case TSP::EDGE_WEIGHT_TYPE::GEO:
            {

                auto p_i = coordinates[i];
                auto p_j = coordinates[j];
                auto p1 = geo_to_radian(p_i[0], p_i[1]);
                auto p2 = geo_to_radian(p_i[0], p_i[1]);

                auto RRR = 6378.388;

                auto q1 = cos( p1.first - p2.first);
                auto q2 = cos( p1.second - p2.second);
                auto q3 = cos( p1.first + p2.second);

                return (int) (RRR * acos( 0.5 * ((1.0 + q1)*q2 -(1.0-q1)*q3)) + 1.0);
            }
        default:
                //throw TSP::PARSER::Inconsistent_definition_exception("Unsupported edge weight type!");
                break;
        }

        return 0;
    }
}
