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
        const std::map<std::string, std::shared_ptr<StateElement>> states_,
        const std::map<std::string, std::shared_ptr<EventElement>> events_,
        const std::map<std::string, std::shared_ptr<GuardElement>> guards_
    );
    ~TransitionElement();

private:
    const std::string_view &type() const override;
};