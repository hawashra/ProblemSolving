#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int M;

    cin >> M;

    string trash;
    while (M--) {

        getline(cin, trash);

        int N, K;

        cin >> N >> K;

        int p;


        bool true_coins[N];

        for (int i = 0; i < N; i++)
            true_coins[i] = false;

        char c;

        for (int i = 0; i < K; i++) {

            cin >> p;

            int left[p];
            int right[p];

            for (int j = 0; j < p; j++)
                cin >> left[j];
            
            for (int j = 0; j < p; j++)
                cin >> right[j];
            
            sort(left, left + p);
            sort(right, right + p);

            cin >> c;

            if (c == '=') 
                for (int j = 0; j < p; j++) {
                    true_coins[left[j] - 1] = true;
                    true_coins[right[j] - 1] = true;
                }
            
            else { // c == '<' or c == '>'

                for (int j = 0; j < N; j++) {
                    if ((binary_search(left, left + p, j + 1) < 0) and (binary_search(right, right + p, j + 1) < 0))
                        true_coins[j] = true;
                }
            }
        }

        int count = 0;
        int coin;

        for (int i = 0; i < N; i++) {
            if (true_coins[i] == false) {
                count++;
                coin = i + 1;
            }
        }

        if (count == 1)
            cout << coin << endl;
        else
            cout << 0 << endl;
        

        if (M != 0)
            cout << endl;

    }
    return 0;
}