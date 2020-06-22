#include "event.h"
#include <string>
#include <string_view>
#include <sstream>
namespace event
{
    void generateEvent(std::ostream &input, const EventElement &event_el)
    {
        constexpr std::string_view class_token = "@class@";
        constexpr std::string_view desc_token = "@description@";
        constexpr std::string_view args_token = "@args@";
        std::string event_class = std::string(""\
        "/**\n"\
        "* \\description @description@\n"\
        "*/\n"\
        "struct @class@ : fsmgen::Event {\n"\
        "@args@\n"\
        "};\n");

        event_class.replace(event_class.find(class_token),  class_token.length(), event_el.name());
        event_class.replace(event_class.find(desc_token), desc_token.length(), event_el.description());

        if (event_el.args().size() > 0)
        {
            std::stringstream variables;
            for (const auto &arg : event_el.args())
            {
                variables << "\t" << arg->dataType() << " " << arg->name() << ";\n";
            }
            const std::string args_str(variables.str());
            event_class.replace(event_class.find(args_token), args_token.length(), args_str);
        }
        input << event_class;
    }
} // namespace event