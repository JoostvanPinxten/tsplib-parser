#include <gtsplibinstance.h>
#include <typeinfo>
#include <parser/exceptions/exceptions.h>
#include <sstream>

using namespace TSPLIB;


GTSPInstance::GTSPInstance(Instance &instance, TSP::TYPE type)
    : BaseInstance(instance, type)
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

/**
 * Converts a string of integers to the cluster definitions
 * as follows:
 * add the nodes to the current cluster in case it is not a boundary token (-1)
 * otherwise, add the node to the current cluster
 *
 * @param cluster_definition
 * @return
 */
bool GTSPInstance::set_gtsp_clusters(std::vector<int> cluster_definition)
{
    // TODO: double check for malformed input; does this method always terminate?

    auto begin = cluster_definition.begin();
    auto cluster = 0;
    while(begin != cluster_definition.end()) {
        auto end = begin;
        while(end != cluster_definition.end() && *end != -1) {
            ++end;
        }

        // ASSUMPTION: the cluster numbers are always incremented by 1, starting from 1
        begin++; // skip the cluster index

        std::vector<int> cluster_list;

        for(auto it = begin; it != end; ++it) {
            cluster_list.push_back((*it) -1);
        }
        clusters.push_back(cluster_list); // potentially expensive?

        cluster++;
        begin = ++end;
    }

    return true;

}


