#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {

        int N; 
        cin >> N;

        int numbers[N];

        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
        }

        sort(numbers, numbers+N);

        cout << "Case " << i << ": " << numbers[N-1] << endl;
    
    }
    return 0;
}