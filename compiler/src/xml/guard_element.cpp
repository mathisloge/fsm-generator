#include "guard_element.h"

GuardElement::GuardElement(const tinyxml2::XMLElement *const root)
    : BaseElement(root)
{
}

void GuardElement::process()
{
    BaseElement::process();
}

const std::string_view &GuardElement::type() const
{
    return type_;
}

GuardElement::~GuardElement()
{
}