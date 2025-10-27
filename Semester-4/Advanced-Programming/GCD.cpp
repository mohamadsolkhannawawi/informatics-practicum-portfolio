#include <iostream>
using namespace std;

void GCD(int a, int b) {
    if(b == 0) {
        cout << a << endl;
    } else {
        GCD(b, a % b);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    GCD(a, b);
    return 0;
}

import sys
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
def main():
    try:
        a, b = map(int, sys.stdin.readline().split())
        hasil = gcd(a, b)
        print(hasil)
    except (IOError, ValueError):
        pass
if __name__ == "__main__":
    main()