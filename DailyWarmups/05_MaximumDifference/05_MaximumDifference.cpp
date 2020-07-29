#include <iostream>
#include <vector>

// function that returns the difference between the highest and lowest numbers in a vector of ints
int MaxDifference(const std::vector<int>& numbers)
{
    // initial variabels
    int numberslength = size(numbers);
    // initially sets both variables to the first outcome as a comparison base
    int largest = numbers[0];
    int lowest = numbers[0];

    // cycles through looking for 
    for (int i = 1; i < numberslength; i++)
    {
        if (numbers[i] < lowest)
            lowest = numbers[i];

        else if (numbers[i] > largest)
            largest = numbers[i];
    }

    int outcome = largest - lowest;

    return outcome;
}

// returns the outcome if the largest number is found after 
int MaxDifference2(const std::vector<int>& numbers)
{
    // initial variables
    int numberslength = size(numbers);
    bool largestselected = false;
    bool lowestselected = false;
    int largest = numbers[0];
    int lowest = numbers[0];

    // loops through looking for a small number first 
    for (int i = 0; i < numberslength; i++)
    {
        if (numbers[i] < lowest && !largestselected)
        {
            lowest = numbers[i];
            lowestselected = true;
            largest = lowest;
        }

        if (numbers[i] > largest && lowestselected)
        {
            largest = numbers[i];
            largestselected = true;
        }
    }

    int outcome = largest - lowest;

    if (outcome == 0)
        outcome = -1;

    return outcome;
}


int main(int argc, char** argv)
{
    std::cout << MaxDifference({ 10, 15, 12, 8, 7, 31, 8 }) << std::endl; // 31 - 7 = 24
    std::cout << MaxDifference({ 12, 0, 4, 9, 2, 5, 8, 3 }) << std::endl; // 12 - 0 = 12
    std::cout << MaxDifference2({ 10, 15, 12, 8, 7, 31, 2 }) << std::endl; // 31 - 7 = 24 
    std::cout << MaxDifference2({ 12, 0, 4, 9, 2, 5, 8, 3 }) << std::endl; // 9 - 0 = 9 
    std::cout << MaxDifference2({ 12, 13, 14, 5, 6, 7, 8 }) << std::endl; // 8 - 5 = 3
    std::cout << MaxDifference2({ 12, 13, 14, 8, 7, 6, 5 }) << std::endl; // ?? cannot select min or max?
    std::cout << MaxDifference2({ 1, 2, 3, 4, 5, 6, 7, 8 }) << std::endl; // ?? cannot select a min or max?
    return 0;
}