#include <iostream>
#include <vector>
#include <algorithm>
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;

void solve(int n);

int main() {
    FAST
    int n;
    bool first = true;
    
    while (scanf("%d", &n) && n) {

        if (!first) {
            cout << "\n";
        }
        first = false;
        getchar();
        solve(n);

    }
}

void solve(int n) {
    bool found = false;
    for (int first = 1234; first <= 98765 / n; ++first) {
        int second = first * n;
        int digits = (first < 10000); // Check if a leading zero is needed for the first number

        int tmp = second;
        while (tmp) {
            digits |= 1 << (tmp % 10);
            tmp /= 10;
        }

        tmp = first;
        while (tmp) {
            digits |= 1 << (tmp % 10);
            tmp /= 10;
        }

        if (digits == (1 << 10) - 1) {
            found = true;
            cout << second << " / " << (first < 10000 ? "0" : "") << first << " = " << n << "\n"; 
        }
    }

    if (!found) {
        cout << "There are no solutions for " << n << ".\n";
    }

}
