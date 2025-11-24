#ifndef CREDIT_ALGORITHM_H
#define CREDIT_ALGORITHM_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Decode.h"
using namespace std;

void CreditAlgorithm(unordered_map<int, vector<int>>& tutorRatings) {
    cout << "Would you like to rate your tutor? (y/n): ";
    char response;
    cin >> response;
    if (response == 'y' || response == 'Y') {
        int tutorID;
        cout << "Enter Tutor ID: ";
        cin >> tutorID;

        if (tutorRatings.find(tutorID) == tutorRatings.end()) {
            cout << "Tutor ID not found.\n";
            return;
        }

        int rating;
        cout << "Enter rating for Tutor " << tutorID << " (1-5): ";
        cin >> rating;
        if (rating < 1 || rating > 5) {
            cout << "Invalid rating. Please enter a number between 1 and 5.\n";
            return;
        }
        tutorRatings[tutorID].push_back(rating);
    }
    cout << "Thank you for your feedback!\n";
}

void displayTutorRatings(const unordered_map<int, vector<int>>& tutorRatings) {
    cout << "\n--- Tutor Ratings Summary ---\n";
    for (const auto& entry : tutorRatings) {
        int tutorID = entry.first;
        const vector<int>& ratings = entry.second;
        if (ratings.empty()) {
            cout << "Tutor " << tutorID << " has no ratings yet.\n";
            continue;
        }
        double average = 0.0;
        for (int rate : ratings) {
            average += rate;
        }
        average /= ratings.size();
        cout << "Tutor " << tutorID << " - Average Rating: " << average << " (" << ratings.size() << " ratings)\n";
    }
    cout << "-----------------------------\n";
}

void tutorAverage(int tutorID, const unordered_map<int, vector<int>>& tutorRatings) {
    auto it = tutorRatings.find(tutorID);
    if (it == tutorRatings.end() || it->second.empty()) {
        cout << "Tutor " << tutorID << " has no ratings yet.\n";
        return;
    }
    const vector<int>& ratings = it->second;
    double average = 0.0;
    for (int rate : ratings) {
        average += rate;
    }
    average /= ratings.size();
    cout << "Tutor " << tutorID << " - Average Rating: " << average << " (" << ratings.size() << " ratings)\n";
}

#endif // CREDIT_ALGORITHM_H