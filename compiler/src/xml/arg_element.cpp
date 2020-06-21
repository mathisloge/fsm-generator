#include "arg_element.h"
#include <stdexcept>
ArgElement::ArgElement(const tinyxml2::XMLElement *const root)
    : BaseElement(root)
{
}

void ArgElement::process()
{
    BaseElement::process();
    const auto type = root_->Attribute("type");
    if(!type) {
        throw std::runtime_error("arg non or invalid type");
    }
    data_type_ = type;
}

const std::string_view &ArgElement::type() const
{
    return type_;
}

const std::string& ArgElement::dataType() const
{
    return data_type_;
}

ArgElement::~ArgElement()
{
}