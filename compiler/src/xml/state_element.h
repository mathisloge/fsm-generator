#pragma once
#include "base_element.h"
class StateElement : public BaseElement
{
    static constexpr std::string_view type_ = "state";
public:
    explicit StateElement(const tinyxml2::XMLElement *const root);
    void process() override;
    ~StateElement();

private:
    const std::string_view &type() const override;
};