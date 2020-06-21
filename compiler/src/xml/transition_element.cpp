#include "transition_element.h"

TransitionElement::TransitionElement(const tinyxml2::XMLElement *const root)
    : BaseElement(root)
{
}
void TransitionElement::process(
    const std::map<std::string, std::shared_ptr<StateElement>> states_,
    const std::map<std::string, std::shared_ptr<EventElement>> events_,
    const std::map<std::string, std::shared_ptr<GuardElement>> guards_)
{
    BaseElement::process();
}

const std::string_view &TransitionElement::type() const
{
    return type_;
}

TransitionElement::~TransitionElement()
{
}