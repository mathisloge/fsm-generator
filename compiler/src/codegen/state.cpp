#include "state.h"
#include <string>
#include <sstream>
namespace state
{
    void generateState(std::ostream &input,
                       const std::shared_ptr<StateElement> &state_el,
                       const std::map<std::string, std::shared_ptr<EventElement>> &events)
    {
        constexpr std::string_view class_token = "@class@";
        constexpr std::string_view desc_token = "@description@";
        constexpr std::string_view cbs_entry_token = "@cbs_entry@";
        constexpr std::string_view cbs_update_token = "@cbs_update@";
        constexpr std::string_view cbs_exit_token = "@cbs_exit@";
        std::string state_class = std::string(""
                                              "/**\n"
                                              "* \\description @description@\n"
                                              "*/\n"
                                              "class @class@ : public fsmgen::State {\n"
                                              "public:\n"
                                              "@cbs_entry@\n"
                                              "@cbs_update@\n"
                                              "@cbs_exit@\n"
                                              "};\n");

        state_class.replace(state_class.find(class_token), class_token.length(), state_el->name());
        state_class.replace(state_class.find(desc_token), desc_token.length(), state_el->description());

        // onEntry
        if (state_el->exit_cbs().size() > 0)
        {
            std::stringstream cbs_ss;
            for (const auto &cb : state_el->entry_cbs())
            {
                if (cb != "___default___")
                {
                    cbs_ss << "\tvoid onEntry(const " << cb << "& event);\n";
                }
                else
                {
                    cbs_ss << "\tvoid onEntry() override;\n";
                }
            }
            const std::string tmp_str(cbs_ss.str());
            state_class.replace(state_class.find(cbs_entry_token), cbs_entry_token.length(), tmp_str);
        }
        else
        {
            state_class.replace(state_class.find(cbs_entry_token), cbs_entry_token.length(), "");
        }
        // onUpdate
        state_class.replace(state_class.find(cbs_update_token), cbs_update_token.length(), [](bool have_update) -> std::string {
            return !have_update ? "" : "\tvoid onUpdate() override;\n";
        }(state_el->have_update_cb()));

        // onExit
        if (state_el->exit_cbs().size() > 0)
        {
            std::stringstream cbs_ss;
            for (const auto &cb : state_el->exit_cbs())
            {
                if (cb != "___default___")
                {
                    cbs_ss << "\tvoid onExit(const " << cb << "& event);\n";
                }
                else
                {
                    cbs_ss << "\tvoid onExit() override;\n";
                }
            }
            const std::string tmp_str(cbs_ss.str());
            state_class.replace(state_class.find(cbs_exit_token), cbs_exit_token.length(), tmp_str);
        }
        else
        {
            state_class.replace(state_class.find(cbs_exit_token), cbs_exit_token.length(), "");
        }
        input << state_class;
    }
} // namespace state