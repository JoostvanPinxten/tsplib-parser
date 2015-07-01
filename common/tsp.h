#ifndef TSP_H
#define TSP_H

namespace TSP {
    enum class TYPE {
        TSP, /// symmetric TSP
        ATSP, /// asymmetric TSP
        GTSP, /// generalized symmetric TSP
        AGTSP, /// generalized asymmetric TSP
        SOP, /// sequential ordering problem
        STUB /// For internal use only
    };

    enum class EDGE_WEIGHT_TYPE {
        TSP, /// symmetric TSP
        ATSP, /// asymmetric TSP
        GTSP, /// generalized symmetric TSP
        AGTSP, /// generalized asymmetric TSP
        SOP /// sequential ordering problem

    };

    enum class NODE_COORD_TYPE {
        TWO_D,
        THREE_D
    };
}

#endif // TSP_H

