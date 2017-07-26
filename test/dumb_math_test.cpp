#include <catch.hpp>
#include <dumb_cpp_math.hpp>

SCENARIO("Test Adder", "[Adder]") {
    GIVEN("An Adder object") {
        dumb_math::Adder adder(10, 20);

        REQUIRE(adder.getFirst() == 10);
        REQUIRE(adder.getSecond() == 20);

        WHEN("first and second are set") {
            THEN("getSum returns the sum") {
                REQUIRE(adder.getSum() == 30);
            }
        }
    }
}
