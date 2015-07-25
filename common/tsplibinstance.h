#ifndef TSPLIBINSTANCE_H
#define TSPLIBINSTANCE_H

#include <map>
#include <vector>
#include <string>

namespace TSPLIB {
    class Instance
    {
    protected:
        std::string name, comment;
        Instance();
        virtual ~Instance();
    public:
        bool set_name(const std::string &_name);
        std::string get_name() const;

        bool set_comment(const std::string &_comment);
        std::string get_comment() const;

        virtual bool set_coordinate_section(std::map<int, std::vector<double> > coordinates) = 0;

    };
}
#endif // TSPLIBINSTANCE_H
