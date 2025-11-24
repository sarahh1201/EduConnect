#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void clearScreen_verify() {
    cout << "Press 0 to clear:";
    int in;
    cin >> in;
    if (in==0){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }
}