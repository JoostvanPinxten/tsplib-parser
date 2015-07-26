#ifndef INCONSISTENTDEFINITION
#define INCONSISTENTDEFINITION
#include <stdexcept>
#include <string>

namespace TSP {
    namespace PARSER {
        struct Inconsistent_definition_exception
            : std::runtime_error {
            Inconsistent_definition_exception(const std::string& what) : std::runtime_error(what){

            }
        };
    }
}
#endif // INCONSISTENTDEFINITION

