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
        TOUR /// A collection of tours
    };

    enum class EDGE_WEIGHT_TYPE {
        EUC_2D,
        EUC_3D,
        MAX_2D,
        MAX_3D,
        CEIL_2D,
    };

    enum class NODE_COORD_TYPE {
        TWO_D,
        THREE_D,
        NONE
    };
}

#endif // TSP_H

