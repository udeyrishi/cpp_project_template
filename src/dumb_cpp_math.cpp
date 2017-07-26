#include <dumb_cpp_math.hpp>
extern "C" {
    #include <dumb_math.h>
}

int dumb_math::Adder::getSum() const {
    return add(first, second);
}

int dumb_math::Adder::getFirst() const {
    return this->first;
}

int dumb_math::Adder::getSecond() const {
    return this->second;
}
