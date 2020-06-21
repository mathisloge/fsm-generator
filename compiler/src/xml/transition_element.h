#pragma once
#include <map>
#include <memory>
#include "base_element.h"
#include "event_element.h"
#include "guard_element.h"
#include "state_element.h"

class TransitionElement : public BaseElement
{
    static constexpr std::string_view type_ = "transition";

public:
    explicit TransitionElement(const tinyxml2::XMLElement *const root);
    void process(
        const std::map<std::string, std::shared_ptr<StateElement>> states,
        const std::map<std::string, std::shared_ptr<EventElement>> events,
        const std::map<std::string, std::shared_ptr<GuardElement>> guards);
    ~TransitionElement();

private:
    const std::string_view &type() const override;
    std::shared_ptr<StateElement> from_;
    std::shared_ptr<StateElement> to_;
    std::shared_ptr<EventElement> event_;
    std::map<std::string, std::shared_ptr<GuardElement>> guards_;

};