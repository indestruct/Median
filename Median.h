//
// Author: mitkovulkov@gmail.com (Mitko Valkov)
// Created on 29.03.19.
//
// This file contains the Median class, which represents a median data
// structure. The class provides operations for adding new number to
// the structure and finding the median for all numbers within the
// structure.
//
// The operation for adding a new number to the structure has a complexity
// of logarithmic time - O(log n), and the operation for finding the
// median has a complexity of constant time - O(1).
//

#ifndef MEDIAN_H
#define MEDIAN_H

#include <iostream>
#include <queue>
#include <vector>

class Median
{
public:
    Median();
    virtual ~Median();

    // Insets a number to the median data structure
    void InsertNumber(const int32_t value);

    // Calculates the median for the current provided set of numbers
    double GetMedian();

private:
    typedef std::priority_queue <int32_t, std::vector<int32_t>, std::less<int32_t>>    MaxPriorityQueueT;
    typedef std::priority_queue <int32_t, std::vector<int32_t>, std::greater<int32_t>> MinPriorityQueueT;

    MaxPriorityQueueT m_maxPrioQueue; // Buffer for the elements that are less or equal the median
    MinPriorityQueueT m_minPrioQueue; // Buffer for the elements that are greater or equal the median

    // Balances the queues that the difference in their size does not exceed one element
    void BalanceQueues();
};


#endif //MEDIAN_H
