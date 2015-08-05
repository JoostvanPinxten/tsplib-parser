#include "gtsplibinstance.h"
#include <typeinfo>
using namespace TSPLIB;


GTSPInstance::GTSPInstance(Instance &instance)
    : BaseInstance(instance)
{
    try {
        GTSPInstance &other = dynamic_cast<GTSPInstance&>(instance);
        // Copy the information from the other GTSP
        // TODO
    } catch(std::bad_cast) {
        // ignore
    }
}

bool GTSPInstance::set_gtsp_cluster_amount(int size)
{
    return true;
}

bool GTSPInstance::set_gtsp_clusters(std::vector<int> cluster_definition)
{
    return true;
}

std::map<unsigned int, std::vector<unsigned int> > GTSPInstance::get_clusters() const
{
    return clusters;
}
