#include "event.h"
#include <string>
#include <sstream>
namespace event
{
    void generateEvent(std::ostream &input, const EventElement &event_el)
    {
        std::string event_class = std::string(""\
        "#include <fsmgen/event.h>\n"\
        "/**\n"\
        "* \\description @description@\n\n"\
        "*/\n"\
        "struct @class@ : fsmgen::Event {\n"\
        "@args@\n"\
        "};\n");

        event_class.replace(event_class.find("@class@"),  std::string("@class@").length(), event_el.name());
        event_class.replace(event_class.find("@description@"), std::string("@description@").length(), event_el.description());

        if (event_el.args().size() > 0)
        {
            std::stringstream variables;
            for (const auto &arg : event_el.args())
            {
                variables << "\t" << arg->dataType() << " " << arg->name() << ";\n";
            }
            const std::string args_str(variables.str());
            event_class.replace(event_class.find("@args@"), std::string("@args@").length(), args_str);
        }
        input << event_class;
    }
} // namespace event