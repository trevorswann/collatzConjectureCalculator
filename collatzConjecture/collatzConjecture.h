//
// Created by Trevor Swann on 10/31/21.
//

#ifndef UNTITLED_COLLATZCONJECTURE_H
#define UNTITLED_COLLATZCONJECTURE_H
#include <iostream>
#include <ctime>
#include <chrono>


class collatzConjecture
{
public:
    collatzConjecture();
    ~collatzConjecture() = default;

private:
    void runCollatzOnNum();             //func for running collatz conjecture on one specific num
    void runCollatzOnRange();           //func for running collatz conjecture on range from 1 to n
    int mathOnEven(int x);              //func for what to do on even #
    int mathOnOdd(int x);               //func for what to do on odd #

    //vars for running collatz on range from 1 to n
    int mostJumpsOverall = 0;
    int numWithMostJumpsOverall = 1;
    int highestNumReachedOverall = 1;
    int numWithHighestNumReachedOverall = 1;

    //vars for calculating execution time
    int64_t startTime;
    int64_t endTime;
    int64_t totalTime;
};

#endif //UNTITLED_COLLATZCONJECTURE_H
