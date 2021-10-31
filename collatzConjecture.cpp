//
// Created by Trevor Swann on 10/31/21.
//
#include "collatzConjecture.h"

collatzConjecture::collatzConjecture() {
    bool keepRunning = true;
    while (keepRunning) {
        bool validFunctionSelection = false;
        std::system("clear");
        while (!validFunctionSelection) {
            //ask user which func they want to run
            std::cout << "********************" << std::endl;
            std::cout << "1) Collatz Conjecture on one specific number" << std::endl;
            std::cout << "2) Collatz Conjecture on a range of numbers from 1 to n" << std::endl;
            std::cout << "999) Quit" << std::endl;
            std::cout << "Enter your selection for which function you would like to run: " << std::endl;
            std::string input;
            std::getline(std::cin, input);
            int userChoice = atoi(input.c_str());

            //switch for what to run based on users choice
            switch (userChoice) {
            case 1:
                //collatz on single num
                validFunctionSelection = true;
                runCollatzOnNum();
                break;
            case 2:
                //collatz on range of nums
                validFunctionSelection = true;
                runCollatzOnRange();
                break;
            case 999:
                //quit
                std::cout << "Thanks for using the Collatz Conjecture calculator!" << std::endl;
                exit(0);
            default:
                //invalid input
                std::system("clear");
                std::cout << "Invalid function selection... please try again..." << std::endl;
                break;
            }
        }

        //prompt user to run again or quit
        std::cout << "Would you like to run the program again? (y/n)" << std::endl;
        std::string runAgainInput;
        std::getline(std::cin, runAgainInput);
        if (runAgainInput.find('n') != std::string::npos || runAgainInput.find('N') != std::string::npos) {
            keepRunning = false;
        }
    }

    //if we get here, the user has chosen to stop running the program
    std::cout << "Thanks for using the Collatz Conjecture calculator!" << std::endl;
    exit(0);
}

void collatzConjecture::runCollatzOnRange() {
    bool haveNum = false;
    int num = 0;
    while (!haveNum) {
        //get integer from user
        std::cout << "Enter any positive integer (5-digits or less): " << std::endl;
        std::string input;
        std::getline(std::cin, input);
        num = strtoul(input.c_str(), 0, 10);

        //check if integer is valid, if not then prompt again (positive, 5-digits or less)
        if (num > 0 && num <= 99999) {
            haveNum = true;
            //grab start time
            startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        } else {
            std::cout << "Invalid selection, try again..." << std::endl;
        }
    }

    //loop through running collatz function from 1 to n, saving the max number of jumps and highest number reached
    for (int i = 1; i <= num; i++) {
        std::cout << "Running collatz on " << i << std::endl;
        int currentNum = i;
        int jumps = 0;
        int highestNumReached = i;
        while (currentNum != 1) {
            if (currentNum % 2 == 0) {
                currentNum = mathOnEven(currentNum);
            } else {
                currentNum = mathOnOdd(currentNum);
            }
            jumps++;
            if (currentNum > highestNumReached) {
                highestNumReached = currentNum;
            }
        }
        if (jumps > mostJumpsOverall) {
            mostJumpsOverall = jumps;
            numWithMostJumpsOverall = i;
        }
        if (highestNumReached > highestNumReachedOverall) {
            highestNumReachedOverall = highestNumReached;
            numWithHighestNumReachedOverall = i;
        }
    }

    //grab ending time and calculate total time
    endTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    totalTime = (endTime - startTime) / 1000;

    //print out results
    std::system("clear");
    std::cout << "The most jumps done for a single number was " << mostJumpsOverall << ", which was reached for the number " << numWithMostJumpsOverall << std::endl;
    std::cout << "The highest number reached overall was " << highestNumReachedOverall << ", which was reached for the number " << numWithHighestNumReachedOverall << std::endl;
    std::cout << "This took " << totalTime << " seconds to complete" << std::endl;
}

void collatzConjecture::runCollatzOnNum() {
    bool haveNum = false;
    int num = 0;
    while (!haveNum) {
        //get integer from user
        std::cout << "Enter any positive integer (8-digits or less): " << std::endl;
        std::string input;
        std::getline(std::cin, input);
        num = strtoul(input.c_str(), 0, 10);

        //check if integer is valid, if not then prompt again (positive, 8-digits or less)
        if (num > 0 && num <= 99999999) {
            haveNum = true;
            //grab start time
            startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        } else {
            std::cout << "Invalid selection, try again..." << std::endl;
        }
    }

    //run collatz function on user integer
    std::system("clear");
    std::cout << "Running collatz on " << num << std::endl;
    int currentNum = num;
    int jumps = 0;
    int highestNumReached = num;
    while (currentNum != 1) {
        if (currentNum % 2 == 0) {
            currentNum = mathOnEven(currentNum);
        } else {
            currentNum = mathOnOdd(currentNum);
        }
        jumps++;
        if (currentNum > highestNumReached) {
            highestNumReached = currentNum;
        }
    }

    //grab ending time and calculate total time
    endTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    totalTime = (endTime - startTime) / 1000;

    //print out results
    std::system("clear");
    std::cout << "Total number of jumps done for " << num << ": " << jumps << std::endl;
    std::cout << "Highest number reached for " << num << ": " << highestNumReached << std::endl;
    std::cout << "This took " << totalTime << " seconds to complete" << std::endl;
}

int collatzConjecture::mathOnEven(int x) {
    //std::cout << "Running mathOnEven for " << x << std::endl;
    return x / 2;
}

int collatzConjecture::mathOnOdd(int x) {
    //std::cout << "Running mathOnOdd for " << x << std::endl;
    return (x * 3) + 1;
}
