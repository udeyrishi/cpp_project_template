#pragma once

namespace dumb_math {

class Adder {
public:
    Adder(int first, int second) : first(first), second(second) { }
    int getFirst() const;
    int getSecond() const;
    int getSum() const;
private:
    const int first;
    const int second;
};

}
