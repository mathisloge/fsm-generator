#include "state_element.h"
StateElement::StateElement(const tinyxml2::XMLElement *const root)
    : BaseElement(root)
{
}
void StateElement::process()
{
    BaseElement::process();
}

const std::string_view &StateElement::type() const
{
    return type_;
}
StateElement::~StateElement()
{
}