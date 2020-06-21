#include "base_element.h"
#include <stdexcept>
BaseElement::BaseElement(const tinyxml2::XMLElement *const root)
    : root_(root)
{
}

void BaseElement::process()
{
    {
        const auto name = root_->FirstChildElement("name");

        if (!name || !name->FirstChild())
        {
            throw(std::runtime_error(std::string("need a name: ") + type().data()));
        }
        name_ = name->FirstChild()->ToText()->Value();
    }
    {
        const auto description = root_->FirstChildElement("description");
        if (description && description->FirstChild())
        {
            description_ = description->FirstChild()->ToText()->Value();
        }
    }
}

const std::string &BaseElement::name() const
{
    return name_;
}
const std::string &BaseElement::description() const
{
    return description_;
}

BaseElement::~BaseElement()
{
}