#include "state_element.h"
StateElement::StateElement(const tinyxml2::XMLElement *const root)
    : BaseElement(root)
{
}
void StateElement::process()
{
    BaseElement::process();
    auto cb_el = root_->FirstChildElement("callbacks");
    if (cb_el)
    {
        processEntry(cb_el);
        processUpdate(cb_el);
        processExit(cb_el);
    }
}

void StateElement::processEntry(const tinyxml2::XMLElement *const cb_root)
{
    entry_cbs_ = processCbFnc(cb_root, "entry", true);
}
void StateElement::processUpdate(const tinyxml2::XMLElement *const cb_root)
{
    const auto default_cb = processCbFnc(cb_root, "update", false);
    have_update_cb_ = (default_cb.size() > 0); // set to true, if we have found the <update/> tag
}
void StateElement::processExit(const tinyxml2::XMLElement *const cb_root)
{
    exit_cbs_ = processCbFnc(cb_root, "exit", true);
}

std::set<std::string> StateElement::processCbFnc(const tinyxml2::XMLElement *const cb_root,
                                                 const std::string &tag,
                                                 const bool overloads) const
{
    std::set<std::string> cbs;
    const auto callback_tag_el = cb_root->FirstChildElement(tag.c_str());
    if (callback_tag_el)
    {
        auto event = callback_tag_el->FirstChildElement("event");
        // we can have a raw <entry/> tag. if this is the case, just add an empty callback.
        if (!event)
        {
            cbs.insert("___default___");
        }
        else if (overloads)
        {
            for (; event; event = event->NextSiblingElement("event"))
            {
                const auto ev_name = event->Attribute("name");
                if (!ev_name)
                {
                    cbs.insert("___default___");
                }
                else
                {
                    cbs.emplace(ev_name);
                }
            }
        }
    }
    return cbs;
}

const std::set<std::string> &StateElement::entry_cbs() const
{
    return entry_cbs_;
}
bool StateElement::have_update_cb() const
{
    return have_update_cb_;
}
const std::set<std::string> &StateElement::exit_cbs() const
{
    return exit_cbs_;
}

const std::string_view &StateElement::type() const
{
    return type_;
}
StateElement::~StateElement()
{
}