#include "event_element.h"

EventElement::EventElement(const tinyxml2::XMLElement *const root)
    : BaseElement(root)
{
}

void EventElement::process()
{
    BaseElement::process();
    auto args_el = root_->FirstChildElement("args");
    if (args_el)
    {
        for (auto arg_el = args_el->FirstChildElement("arg"); arg_el; arg_el = arg_el->NextSiblingElement("arg"))
        {
            auto arg = std::make_unique<ArgElement>(arg_el);
            arg->process();
            args_.push_back(std::move(arg));
        }
    }
}

const std::string_view &EventElement::type() const
{
    return type_;
}

const std::vector<std::unique_ptr<ArgElement>>& EventElement::args() const
{
    return args_;
}

EventElement::~EventElement()
{
}