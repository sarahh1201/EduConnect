#include <iostream>
#include "MinHeapTree.h"
using namespace std;

int main()
{
    // Example for a basic implementation of EduConnect Student Requests with a Min Heap
    // Suppose we want to organize student requests based on their urgencies and they need variable IDs to indicate importance:
    MinHeap minHeap(6); // Base initializer as an example heap
    vector<int> arr = { 10, 4, 8, 3, 9, 5 }; // Some template priority IDs, lower value = higher urgency
    minHeap.buildHeap(arr); // We now insert this template array into our minHeap
    cout << "Current minHeap organization: "; // Show the current structure
    minHeap.print(); // Should vaguely organize all IDs in a manner that the highest urgency request is always on the top
    
    cout << endl << "Most urgent request ID: #" << minHeap.peek() << endl;

    // Now suppose a new student put in a request that is of extreme urgency:
    minHeap.insert(1); // Real important
    cout << endl << "New request pushed in." << endl;
    cout << "Current minHeap organization: "; // And just rerun the previous thing again
    minHeap.print();

    cout << endl << "Most urgent request ID: #" << minHeap.peek() << endl;

    return 0;
}
