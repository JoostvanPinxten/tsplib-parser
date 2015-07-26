#include "tsplibtourinstance.h"

using namespace TSPLIB;

TourInstance::TourInstance(const Instance &instance)
{
    comment = instance.get_comment();
    name = instance.get_name();
}

TourInstance::~TourInstance() {

}
