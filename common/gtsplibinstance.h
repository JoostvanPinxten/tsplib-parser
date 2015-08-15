#ifndef GTSPLIBINSTANCE_H
#define GTSPLIBINSTANCE_H
#include <basetsplibinstance.h>
#include <vector>

namespace TSPLIB {
class GTSPInstance : public BaseInstance
{
private:
    std::vector<std::vector<int>> clusters;
public:
    GTSPInstance(Instance &instance, TSP::TYPE type);

    bool set_gtsp_cluster_amount(int size);
    bool set_gtsp_clusters(std::vector<int> cluster_definition);
    virtual std::vector<std::vector<int> > get_clusters() const
    {
        return clusters;
    }
};
}
#endif // GTSPLIBINSTANCE_H
