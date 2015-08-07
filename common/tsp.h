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
        TOUR, /// A (collection of) tour(s)
        NONE
    };

    enum class EDGE_WEIGHT_TYPE {
        EUC_2D,
        EUC_3D,
        MAX_2D,
        MAX_3D,
        CEIL_2D,
        EXPLICIT,
        GEO,
        ATT,
        XRAY1,
        XRAY2,
        SPECIAL
    };

    enum class EDGE_WEIGHT_FORMAT {
        FUNCTION,
        FULL_MATRIX,
        UPPER_ROW,
        LOWER_ROW,
        UPPER_DIAG_ROW,
        LOWER_DIAG_ROW,
        UPPER_COL,
        LOWER_COL,
        UPPER_DIAG_COL,
        LOWER_DIAG_COL
    };

    enum class NODE_COORD_TYPE {
        TWO_D,
        THREE_D,
        NONE
    };

    enum class DISPLAY_DATA_TYPE {
        COORD_DISPLAY,
        TWOD_DISPLAY,
        NO_DISPLAY
    };
}

#endif // TSP_H

