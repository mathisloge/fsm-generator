#include "fsm_element.h"

#include <iostream>
FsmElement::FsmElement(const tinyxml2::XMLElement *const root)
    : BaseElement(root),
      initial_state_(nullptr)
{
}


// todo: run through the complete fsm and check if we got some double path
void FsmElement::validate() const
{
}

void FsmElement::process()
{
    BaseElement::process();
    {
        const auto version = root_->FirstChildElement("version");
        if (version && version->FirstChild())
        {
            version_ = version->FirstChild()->ToText()->Value();
        }
    }
    std::cout << "FSM Name: " << name_ << " with description " << description_ << " and version " << version_ << std::endl;
    processStates();
    processEvents();
    processGuards();
    processTransitions();

    validate();
}

void FsmElement::processStates()
{
    const auto states = root_->FirstChildElement("states");
    if (!states)
    {
        throw(std::runtime_error("need min one state"));
    }
    for (auto state = states->FirstChildElement("state"); state; state = state->NextSiblingElement("state"))
    {
        auto state_el = std::make_shared<StateElement>(state);
        state_el->process();
        if (states_.find(state_el->name()) != states_.end())
        {
            throw(std::runtime_error("states need a unique name"));
        }

        std::cout << "found state " << state_el->name() << std::endl;
        states_[state_el->name()] = state_el;
    }
    auto initial_state = states->FirstChildElement("initial");
    if (!initial_state)
    {
        throw std::runtime_error("need an initial state");
    }
    auto initial_state_name = initial_state->Attribute("name");
    if (!initial_state_name)
    {
        throw std::runtime_error("initial state needs an attribute name");
    }
    auto initial_state_it = states_.find(initial_state_name);
    if (initial_state_it == states_.end())
    {
        throw std::runtime_error("initial state not found");
    }
    initial_state_ = initial_state_it->second;
    std::cout << "initial state is " << initial_state_->name() << std::endl;
}

void FsmElement::processEvents()
{
    const auto events = root_->FirstChildElement("events");
    if (!events)
    {
        throw(std::runtime_error("need some events"));
    }
    for (auto event = events->FirstChildElement("event"); event; event = event->NextSiblingElement("event"))
    {
        auto event_el = std::make_shared<EventElement>(event);
        event_el->process();
        if (events_.find(event_el->name()) != events_.end())
        {
            throw(std::runtime_error("events need a unique name"));
        }

        std::cout << "found event " << event_el->name() << std::endl;
        events_[event_el->name()] = event_el;
    }
}

void FsmElement::processGuards()
{
    const auto guards = root_->FirstChildElement("guards");
    if (!guards)
    {
        std::cout << "no guards detected" << std::endl;
        return;
    }
    for (auto guard = guards->FirstChildElement("guard"); guard; guard = guard->NextSiblingElement("guard"))
    {
        auto guard_el = std::make_shared<GuardElement>(guard);
        guard_el->process();
        if (guards_.find(guard_el->name()) != guards_.end())
        {
            throw(std::runtime_error("events need a unique name"));
        }

        std::cout << "found guard " << guard_el->name() << std::endl;
        guards_[guard_el->name()] = guard_el;
    }
}

void FsmElement::processTransitions()
{
    const auto transitions = root_->FirstChildElement("transitions");
    if (!transitions)
    {
        throw(std::runtime_error("need some transitions"));
        return;
    }
    for (auto transition = transitions->FirstChildElement("transition"); transition; transition = transition->NextSiblingElement("transition"))
    {
        auto transition_el = std::make_shared<TransitionElement>(transition);
        transition_el->process(states_, events_, guards_);

        std::cout << "found transition " << transition_el->name() << std::endl;
    }
}

const std::string_view &FsmElement::type() const
{
    return type_;
}

const std::map<std::string, std::shared_ptr<StateElement>> &FsmElement::states() const
{
    return states_;
}
const std::map<std::string, std::shared_ptr<EventElement>> &FsmElement::events() const
{
    return events_;
}
const std::map<std::string, std::shared_ptr<GuardElement>> &FsmElement::guards() const
{
    return guards_;
}

FsmElement::~FsmElement()
{
}