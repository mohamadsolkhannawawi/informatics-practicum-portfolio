#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(vector<int>& array) {
    int n = array.size();
    vector<int> length(n, 1);

    cout << "Initial length array: ";
    for (int l : length) cout << l << " "; 
    cout << endl;

    for (int k = 0; k < n; k++) {
        // length[k] = 1
        cout << "Processing element array[" << k << "] = " << array[k] << endl;
        for (int i = 0; i < k; i++) {
            cout << "  Comparing with array[" << i << "] = " << array[i];
            if (array[i] < array[k]) {
                int newLength = length[i] + 1;
                cout << " --> array[" << i << "] < array[" << k << "], updating length[" << k << "] from " << length[k] << " to " << max(length[k], newLength);
                length[k] = max(length[k], newLength);
            } else {
                cout << " --> no update needed";
            }
            cout << endl;
        }
        cout << "  Length array after processing array[" << k << "]: ";
        for (int l : length) cout << l << " ";
        cout << endl;
    }

    int result = *max_element(length.begin(), length.end());
    cout << "Final length array: ";
    for (int l : length) cout << l << " ";
    cout << endl;

    return result;
}

int main() {
    vector<int> array = {3, 1, 8, 2, 5, 6, 7, 4};
    cout << "Input array: ";
    for (int a : array) cout << a << " ";
    cout << endl;

    cout << "Length of LIS: " << longestIncreasingSubsequence(array) << endl;
    return 0;
}
