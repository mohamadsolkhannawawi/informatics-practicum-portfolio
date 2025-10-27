#include <iostream>
#include <vector>
using namespace std;

// Function to check if it is possible to process k jobs in x time
bool valid(int x, vector<int>& p, int k) {
    int total_jobs = 0;
    cout << "Checking valid(" << x << "): ";
    for (int time : p) {
        int jobs = x / time;  // Maximum jobs per machine
        total_jobs += jobs;
        cout << "[" << jobs << " jobs from machine (time = " << time << ")] ";
    }
    cout << "=> Total jobs = " << total_jobs << (total_jobs >= k ? " (VALID)" : " (NOT VALID)") << endl;
    return total_jobs >= k;
}

// Function to find the minimum time required to process all jobs
int minProcessingTime(int k, vector<int>& p) {
    int left = 0, right = k * p[0]; // Upper bound z = k * p1 (here, z = 8 * 2 = 16)
    cout << "Initial range: [" << left << ", " << right << "]\n";

    while (left < right) {
        int mid = (left + right) / 2;
        cout << "Binary search: mid = " << mid << " | Range = [" << left << ", " << right << "]" << endl;
        
        if (valid(mid, p, k)) {
            cout << "Valid -> Updating right = " << mid << endl;
            right = mid;  // Try to minimize x
        } else {
            cout << "Not valid -> Updating left = " << (mid + 1) << endl;
            left = mid + 1;
        }
        cout << "Updated range: [" << left << ", " << right << "]\n\n";
    }
    
    return left;
}

int main() {
    int k = 8;
    vector<int> p = {2, 3, 7};
    
    cout << "Finding minimum processing time...\n\n";
    int result = minProcessingTime(k, p);
    
    cout << "\nMinimum processing time: " << result << endl;
    return 0;
}
