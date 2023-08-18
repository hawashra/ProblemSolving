#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);

int main(void) {
    // not solved. (at least i tried)

    int T;
    std::cin >> T;
    int tc = 0;
    while (T--) {
        tc++;
        int N;
        std::cin >> N;

        int petrol_at_station[N];
        int petrol_needed_to_next_station[N];

        for (int i = 0; i < N; i++) {
            std::cin >> petrol_at_station[i];
        }
        for (int i = 0; i < N; i++) {
            std::cin >> petrol_needed_to_next_station[i];
        }

    }
    return 0;
}