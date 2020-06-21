#pragma once
#include "base_element.h"

class EventElement : public BaseElement
{
    static constexpr std::string_view type_ = "event";
public:
    explicit EventElement(const tinyxml2::XMLElement *const root);
    void process() override;
    ~EventElement();

private:
    const std::string_view &type() const override;
};