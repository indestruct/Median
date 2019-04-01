//
// Author: mitkovulkov@gmail.com (Mitko Valkov)
// Created on 29.03.19.
//
// This file contains the implementation of Median class. The implementation
// is optimized to find fast the median of a set of numbers, by keeping
// the elements in almost sorted order, in two priority queues - one for the
// elements less or equal the median (left side of the median), the second
// for the elements greater or equal the median (right side of the median).
//
// The queue that stores the left side of the median is sorted by the maximum
// element, and the queue that stores the right side of the median is sorted
// by the minimum element.
//

#include "Median.h"

Median::Median()
{
}

Median::~Median()
{
}

// Insert the number to the left or to the right priority queue
// and balance them if after insertion they become unbalanced
void Median::InsertNumber(const int32_t value)
{
    if ((!m_maxPrioQueue.empty()) && (value > m_maxPrioQueue.top()))
    {
        m_minPrioQueue.push(value);
    }
    else
    {
        m_maxPrioQueue.push(value);
    }

    // Balance the queues if after insertion they become unbalanced
    BalanceQueues();
}

// Return the median value based on the current set of numbers
double Median::GetMedian()
{
    // Lambda for calculating if the set length is even
    auto isLengthEven = [=](){return ((m_minPrioQueue.size() + m_maxPrioQueue.size()) % 2) == 0;};

    double currentMedian = 0.0;

    if ((m_minPrioQueue.size() == 0) && (m_maxPrioQueue.size() == 0))
    {
        throw "Cannot get median of empty set.";
    }

    // If the length is even, the median is calculated as the sum of the two 
    // middle elements, divided by two, and if it is odd, as the middle element
    if (isLengthEven())
    {
        currentMedian = ((m_maxPrioQueue.top() + m_minPrioQueue.top()) / 2.0);
    }
    else
    {
        // In case of odd length, the middle element is in the queue
        // that has 1 more element than the other
        if (m_maxPrioQueue.size() > m_minPrioQueue.size())
        {
            currentMedian = static_cast<double> (m_maxPrioQueue.top());
        }
        else
        {
            currentMedian = static_cast<double> (m_minPrioQueue.top());
        }
    }

    return currentMedian;
}

// Check if the queues are unbalanced and balance them by moving element
// from the queue with more elements to the queue with less elements
void Median::BalanceQueues()
{
    auto isUnbalanced = [](size_t leftSize, size_t rightSize){return (leftSize - rightSize) > 1;};

    // Check if the max queue has more elements than the min queue,
    // and if so, move element from max to the min queue
    if ((m_maxPrioQueue.size() > m_minPrioQueue.size()) &&
        (isUnbalanced(m_maxPrioQueue.size(), m_minPrioQueue.size())))
    {
        auto maxValue = m_maxPrioQueue.top();
        m_maxPrioQueue.pop();
        m_minPrioQueue.push(maxValue);
    }

    // Check if the min queue has more elements than the max queue,
    // and if so, move element from min to the max queue
    if ((m_minPrioQueue.size() > m_maxPrioQueue.size()) &&
        (isUnbalanced(m_minPrioQueue.size(), m_maxPrioQueue.size())))
    {
        auto minValue = m_minPrioQueue.top();
        m_minPrioQueue.pop();
        m_maxPrioQueue.push(minValue);
    }
}
