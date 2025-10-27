// #include <iostream>
// #include <vector>
// #include <deque>
// #include <string>
// #include <algorithm>
// #include <functional>

// using namespace std;

// string solve(const vector<int>& finalOrder) {
//     int N = finalOrder.size();
//     deque<int> dq(finalOrder.begin(), finalOrder.end());
//     string result;

//     function<bool(deque<int>&, string&)> reconstruct = [&](deque<int>& dq, string& res) -> bool {
//         if (dq.size() == 1) return true;

//         // Coba lipat dari sisi kiri (cekungan ke atas 'A')
//         if (dq.front() < dq.back()) {
//             int left = dq.front();
//             dq.pop_front();
//             res += 'A';
//             if (reconstruct(dq, res)) return true;
//             res.pop_back();
//             dq.push_front(left);
//         }

//         // Coba lipat dari sisi kanan (cekungan ke bawah 'B')
//         if (dq.back() < dq.front()) {
//             int right = dq.back();
//             dq.pop_back();
//             res += 'B';
//             if (reconstruct(dq, res)) return true;
//             res.pop_back();
//             dq.push_back(right);
//         }

//         return false;
//     };

//     if (!reconstruct(dq, result)) return "INVALID";
//     reverse(result.begin(), result.end());
//     return result;
// }

// int main() {
//     string subsoal;
//     int N;
//     cin >> subsoal >> N;

//     vector<int> finalOrder(N);
//     for (int i = 0; i < N; i++) {
//         cin >> finalOrder[i];
//     }

//     cout << solve(finalOrder) << endl;
//     return 0;
// }




