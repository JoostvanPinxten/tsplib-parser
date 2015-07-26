#ifndef TOURINSTANCE_H
#define TOURINSTANCE_H
#include <tsplibinstance.h>

namespace TSPLIB {
    class TourInstance : public Instance
    {
    public:
        TourInstance(const Instance& instance);
        ~TourInstance();
    };
}
#endif // TOURINSTANCE_H
