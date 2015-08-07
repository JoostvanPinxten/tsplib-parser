#ifndef TSPLIBINSTANCE_H
#define TSPLIBINSTANCE_H

#include <map>
#include <vector>
#include <string>
#include <tsp.h>

namespace TSPLIB {
    class Instance
    {

    protected:
        std::string name, comment;
        Instance(TSP::TYPE type);
        TSP::TYPE type;
    public:
        virtual ~Instance() = 0;
        bool set_name(const std::string &_name);
        std::string get_name() const;

        bool set_comment(const std::string &_comment);
        std::string get_comment() const;
    };
}
#endif // TSPLIBINSTANCE_H
