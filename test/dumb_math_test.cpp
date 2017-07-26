/**
 Copyright 2017 Udey Rishi
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
    http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

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
