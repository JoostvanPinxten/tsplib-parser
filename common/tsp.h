#ifndef TSP_H
#define TSP_H

namespace TSP {
    enum class TYPE {
        TSP, /// symmetric TSP
        ATSP, /// asymmetric TSP
        GTSP, /// generalized symmetric TSP
        AGTSP, /// generalized asymmetric TSP
        SOP, /// sequential ordering problem
        CVRP, /// Capacitated vehicle routing problem
        TOUR, /// A collection of tours
        STUB /// For internal use only
    };

    enum class EDGE_WEIGHT_TYPE {

    };

    enum class NODE_COORD_TYPE {
        TWO_D,
        THREE_D,
        NONE
    };
}

#endif // TSP_H

