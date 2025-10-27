#include <iostream>
#include <vector>
#include <algorithm> // Untuk std::min
using namespace std;

const int MAX_SIZE = 1000;
const int INF = 1e9;

vector<bool> ready(MAX_SIZE, false);
vector<int> value(MAX_SIZE, INF);
vector<int> coins = {1, 3, 4}; // Contoh koin

int solve(int x) {
    if (x == 0) return 0;
    if (ready[x]) return value[x];

    int best = INF;
    for (auto c : coins) {
        if (x - c >= 0) {
            best = min(best, solve(x - c) + 1);
        }
    }

    ready[x] = true;
    value[x] = best;
    return best;
}

int main() {
    int x = 6;
    cout << solve(x) << endl;
    return 0;
}
