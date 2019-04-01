#include <iostream>
#include "Median.h"

int main() {
    Median newMedian;

    try
    {
        auto res = newMedian.GetMedian();
    }
    catch (const char* exception)
    {
        std::cout << exception << std::endl;
    }


    newMedian.InsertNumber(1);

    std::cout << "Median is " << newMedian.GetMedian() << "\n";

    newMedian.InsertNumber(6);

    std::cout << "Median is " << newMedian.GetMedian() << "\n";

    newMedian.InsertNumber(4);

    std::cout << "Median is " << newMedian.GetMedian() << "\n";

    newMedian.InsertNumber(3);
    newMedian.InsertNumber(2);
    newMedian.InsertNumber(5);
    newMedian.InsertNumber(3);
    newMedian.InsertNumber(3);

    // 1 2 3 3 3 4 5 6

    std::cout << "Median is " << newMedian.GetMedian() << "\n";

    return 0;
}
