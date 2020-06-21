#include "transition_element.h"
#include <stdexcept>
TransitionElement::TransitionElement(const tinyxml2::XMLElement *const root)
    : BaseElement(root)
{
}
void TransitionElement::process(
    const std::map<std::string, std::shared_ptr<StateElement>> states,
    const std::map<std::string, std::shared_ptr<EventElement>> events,
    const std::map<std::string, std::shared_ptr<GuardElement>> guards)
{
    BaseElement::process();
    { // from
        auto from_el = root_->FirstChildElement("from");
        if (!from_el)
        {
            throw std::runtime_error("transition needs an starting state");
        }
        if (!from_el->Attribute("name"))
        {
            throw std::runtime_error("transition start needs an state name");
        }

        auto state_it = states.find(from_el->Attribute("name"));
        if (state_it == states.end())
        {
            throw std::runtime_error("transition start state can't be found");
        }
        from_ = state_it->second;
    }
    { // to
        auto to_el = root_->FirstChildElement("to");
        if (!to_el)
        {
            throw std::runtime_error("transition needs an ending state");
        }
        if (!to_el->Attribute("name"))
        {
            throw std::runtime_error("transition to needs a state name");
        }

        auto state_it = states.find(to_el->Attribute("name"));
        if (state_it == states.end())
        {
            throw std::runtime_error("transition to state can't be found");
        }
        to_ = state_it->second;
    }
    { // event
        auto event_el = root_->FirstChildElement("event");
        if (!event_el)
        {
            throw std::runtime_error("transition needs an event");
        }
        if (!event_el->Attribute("name"))
        {
            throw std::runtime_error("transition event needs a name");
        }

        auto event_it = events.find(event_el->Attribute("name"));
        if (event_it == events.end())
        {
            throw std::runtime_error("transition event can't be found");
        }
        event_ = event_it->second;
    }
    { // guards
        auto guards_el = root_->FirstChildElement("guards");
        if (guards_el)
        {
            for (auto guard_el = guards_el->FirstChildElement("guard"); guard_el; guard_el = guard_el->NextSiblingElement("guard"))
            {
                if (!guard_el->Attribute("name"))
                {
                    throw std::runtime_error("transition guard needs a name");
                }
                auto guard_it = guards.find(guard_el->Attribute("name"));
                if (guard_it == guards.end())
                {
                    throw std::runtime_error("transition guard can't be found");
                }
                guards_.insert(*guard_it);
            }
        }
    }
}

const std::string_view &TransitionElement::type() const
{
    return type_;
}

TransitionElement::~TransitionElement()
{
}