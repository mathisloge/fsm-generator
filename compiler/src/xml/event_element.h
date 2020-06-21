#pragma once
#include <vector>
#include <memory>
#include "base_element.h"
#include "arg_element.h"

class EventElement : public BaseElement
{
    static constexpr std::string_view type_ = "event";
public:
    explicit EventElement(const tinyxml2::XMLElement *const root);
    void process() override;
    ~EventElement();

    const std::vector<std::unique_ptr<ArgElement>>& args() const;

private:
    const std::string_view &type() const override;
    std::vector<std::unique_ptr<ArgElement>> args_;
};