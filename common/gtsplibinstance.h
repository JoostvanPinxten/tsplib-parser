#ifndef GTSPLIBINSTANCE_H
#define GTSPLIBINSTANCE_H
#include <basetsplibinstance.h>
#include <map>
#include <vector>

namespace TSPLIB {
class GTSPInstance : public BaseInstance
{
private:
    std::map<unsigned int, std::vector<unsigned int>> clusters;
public:
    GTSPInstance(Instance &instance);

    bool set_gtsp_cluster_amount(int size);
    bool set_gtsp_clusters(std::vector<int> cluster_definition);
    std::map<unsigned int, std::vector<unsigned int> > get_clusters() const;
};
}
#endif // GTSPLIBINSTANCE_H
