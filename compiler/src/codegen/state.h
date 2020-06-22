#pragma once
#include <ostream>
#include "../xml/state_element.h"

namespace state {
    void generateState(std::ostream& input, const StateElement& state_el);
}