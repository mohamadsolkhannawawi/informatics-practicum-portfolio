#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

tuple<int,int,int> gcd(int a, int b) {
    if (b == 0) {
        return {1, 0, a}; // x = 1, y = 0, gcd = a
    } else {
        int x, y, g;
        tie(x, y, g) = gcd(b, a % b); // rekursi
        return {y, x - (a / b) * y, g}; // rumus penyesuaian
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    int x, y, g;
    tie(x, y, g) = gcd(a, b);
    cout << "GCD: " << g << ", x: " << x << ", y: " << y << endl;
    return 0;
}