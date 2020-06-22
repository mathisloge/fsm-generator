#pragma once
#include <set>
#include <string>
#include "base_element.h"
class StateElement : public BaseElement
{
    static constexpr std::string_view type_ = "state";

public:
    explicit StateElement(const tinyxml2::XMLElement *const root);
    void process() override;
    const std::set<std::string>& entry_cbs() const;
    bool have_update_cb() const;
    const std::set<std::string>& exit_cbs() const;
    ~StateElement();

private:
    void processEntry(const tinyxml2::XMLElement *const cb_root);
    void processUpdate(const tinyxml2::XMLElement *const cb_root);
    void processExit(const tinyxml2::XMLElement *const cb_root);
    std::set<std::string> processCbFnc(const tinyxml2::XMLElement *const cb_root,
                                       const std::string &tag,
                                       const bool overloads) const;

private:
    const std::string_view &type() const override;
    // we can only have one function per event
    std::set<std::string> entry_cbs_;
    bool have_update_cb_;
    std::set<std::string> exit_cbs_;
};