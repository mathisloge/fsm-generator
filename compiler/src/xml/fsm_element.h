#pragma once
#include <map>
#include <vector>
#include <memory>
#include "base_element.h"
#include "state_element.h"
#include "event_element.h"
#include "guard_element.h"
#include "transition_element.h"

class FsmElement : public BaseElement
{
    static constexpr std::string_view type_ = "fsm";

public:
    explicit FsmElement(const tinyxml2::XMLElement *const root);
    void process() override;
    const std::map<std::string, std::shared_ptr<StateElement>>& states() const;
    const std::map<std::string, std::shared_ptr<EventElement>>& events() const;
    const std::map<std::string, std::shared_ptr<GuardElement>>& guards() const;
    ~FsmElement();

private:
    const std::string_view &type() const override;
    void processStates();
    void processEvents();
    void processGuards();
    void processTransitions();

private:
    std::string version_;
    std::map<std::string, std::shared_ptr<StateElement>> states_;
    std::map<std::string, std::shared_ptr<EventElement>> events_;
    std::map<std::string, std::shared_ptr<GuardElement>> guards_;
    std::vector<std::shared_ptr<TransitionElement>> transitions_;
    std::shared_ptr<StateElement> initial_state_;
};