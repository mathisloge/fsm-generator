#include "event_element.h"

EventElement::EventElement(const tinyxml2::XMLElement *const root)
    : BaseElement(root)
{
}

void EventElement::process()
{
    BaseElement::process();
}

const std::string_view &EventElement::type() const
{
    return type_;
}

EventElement::~EventElement()
{
}