//
// Author: mitkovulkov@gmail.com (Mitko Valkov)
// Created on 29.03.19.
//
// This file contains the Median class test cases, which are executed
// automatically.
//

#include <iostream>
#include <tuple>
#include <vector>

#include "Median.h"

std::vector<std::tuple<std::string, std::vector<int32_t>, double>> testCases =
{
        {"Empty set", {}, 0.0},
        {"Single element set", {2}, 2.0},
        {"Two element set", {3,2}, 2.5},
        {"Three element set", {4,2,8}, 4.0}, // 2 4 8
        {"Ten element set", {6,1,5,6,6,8,2,7,4,3}, 5.5}, // 1 2 3 4 5  6 6 6 7 8
        {"Same element set", {5,5,5,5,5}, 5.0},
};

int main() {

    for (auto &test : testCases) {
        Median<int32_t> testMedian;

        for (const auto &num : std::get<1>(test)) {
            testMedian.InsertNumber(num);
        }

        try {
            auto result = testMedian.GetMedian();

            if (result == std::get<2>(test))
            {
                std::cout << "Test " << std::get<0>(test) << " passed" << std::endl;
            }
            else
            {
                std::cout << "Test " << std::get<0>(test) << " failed" << std::endl;
            }
        }
        catch (const char *exception) {
            std::cout << exception << std::endl;
            if (0 == std::get<1>(test).size())
            {
                std::cout << "Test " << std::get<0>(test) << " passed" << std::endl;
            }
            else
            {
                std::cout << "Test " << std::get<0>(test) << " failed" << std::endl;
            }
        }
    }

    return 0;
}
