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
    unsigned int cluster = 0; // convert to internal 0-based indexing
    for(int node : cluster_definition) {
        if(node == -1) {
            cluster++;
        } else if(0 >= node || (unsigned int) node > dimension) {
            std::ostringstream err;
            err << "Node value " << node << " is out of range! Dimension of the problem is " << dimension;
            throw TSP::PARSER::Inconsistent_definition_exception(err.str());
        } else {
            if(clusters.size() < cluster + 1) {
                clusters.resize(cluster + 1);
            }
            clusters[cluster].push_back(node-1); // convert to internal 0-based indexing
        }
    }
    return true;
}

std::vector<std::vector<unsigned int>> GTSPInstance::get_clusters() const
{
    return clusters;
}
