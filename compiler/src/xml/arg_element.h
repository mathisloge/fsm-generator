#pragma once
#include "base_element.h"
class ArgElement : public BaseElement
{
    static constexpr std::string_view type_ = "arg";

public:
    explicit ArgElement(const tinyxml2::XMLElement *const root);
    void process() override;
    const std::string& dataType() const;
    ~ArgElement();

private:
    const std::string_view &type() const override;
    std::string data_type_;
};