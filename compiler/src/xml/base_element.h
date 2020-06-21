#pragma once
#include <string>
#include <tinyxml2.h>

class BaseElement
{

public:
    explicit BaseElement(const tinyxml2::XMLElement *const root);
    virtual void process();
    const std::string &name() const;
    const std::string &description() const;
    virtual ~BaseElement();

protected:
    virtual const std::string_view &type() const = 0;

protected:
    const tinyxml2::XMLElement *const root_;
    std::string name_;
    std::string description_;
};