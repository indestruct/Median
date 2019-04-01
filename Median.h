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

template <class T>
class Median
{
public:
    Median();
    virtual ~Median();

    // Insets a number to the median data structure
    void InsertNumber(const T value);

    // Calculates the median for the current provided set of numbers
    double GetMedian();

private:
    typedef std::priority_queue <T, std::vector<T>, std::less<T>>    MaxPriorityQueueT;
    typedef std::priority_queue <T, std::vector<T>, std::greater<T>> MinPriorityQueueT;

    MaxPriorityQueueT m_maxPrioQueue; // Buffer for the elements that are less or equal the median
    MinPriorityQueueT m_minPrioQueue; // Buffer for the elements that are greater or equal the median

    // Balances the queues that the difference in their size does not exceed one element
    void BalanceQueues();
};

//
// Code below contains the implementation of Median class. The implementation
// is optimized to find fast the median of a set of numbers, by keeping
// the elements in almost sorted order, in two priority queues - one for the
// elements less or equal the median (left side of the median), the second
// for the elements greater or equal the median (right side of the median).
//
// The queue that stores the left side of the median is sorted by the maximum
// element, and the queue that stores the right side of the median is sorted
// by the minimum element.
//

template <class T>
Median<T>::Median()
{
    static_assert(std::is_arithmetic<T>::value, "The type is not an arithmetic type.");
}

template <class T>
Median<T>::~Median()
{
}

// Insert the number to the left or to the right priority queue
// and balance them if after insertion they become unbalanced
template <class T>
void Median<T>::InsertNumber(const T value)
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
template <class T>
double Median<T>::GetMedian()
{
    // Lambda for calculating if the set length is even
    auto isLengthEven = [&](){return ((m_minPrioQueue.size() + m_maxPrioQueue.size()) % 2) == 0;};

    double currentMedian = 0.0;

    if ((m_minPrioQueue.size() == 0) && (m_maxPrioQueue.size() == 0))
    {
        throw "Cannot get median of empty set.";
    }

    // If the length is even, the median is calculated as the
    // and if it is odd,
    if (isLengthEven())
    {
        currentMedian = ((m_maxPrioQueue.top() + m_minPrioQueue.top()) / 2.0);
    }
    else
    {
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
template <class T>
void Median<T>::BalanceQueues()
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

#endif //MEDIAN_H

