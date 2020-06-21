#pragma once
#include "base_element.h"

class GuardElement : public BaseElement
{
    static constexpr std::string_view type_ = "guard";
public:
    explicit GuardElement(const tinyxml2::XMLElement *const root);
    void process() override;
    ~GuardElement();

private:
    const std::string_view &type() const override;
};