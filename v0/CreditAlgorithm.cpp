#include <iostream>
#include <vector>
#include <unordered_map>
#include "CreditAlgorithm.h"
using namespace std;

int main(){
    unordered_map<int, vector<int>> tutorRatings = {
        {101, {}},
        {102, {}},
        {103, {}},
        {104, {}},
        {105, {}}
    };


    CreditAlgorithm(tutorRatings);
    displayTutorRatings(tutorRatings);
    CreditAlgorithm(tutorRatings);
    displayTutorRatings(tutorRatings);
    CreditAlgorithm(tutorRatings);
    displayTutorRatings(tutorRatings);
    CreditAlgorithm(tutorRatings);
    displayTutorRatings(tutorRatings);

    tutorAverage(101, tutorRatings);
    
    return 0;
}
