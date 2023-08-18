#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define endl "\n"


int main () {
    FAST
    int N;
    string str1, str2;
    while (cin >> N && N) {

        vector<pair<string, string>> pairs;
        string arr[N];
        for (int i = 0; i < N; i++) {
            cin >> str1 >> str2;
            pairs.push_back(make_pair(str1, str2));
        }
        int currIndex = -1;
        for (int i = 0; i < N; i++) {
            string word = pairs[i].first;
            int len = pairs[i].second.length();

            while (len) {
                currIndex = (1+currIndex) % N;

                if (arr[currIndex] == "") len--;
            }

            arr[currIndex] = word;
        }

        for (int i = 0; i < N-1; i++) {
            cout << arr[i] << " ";
        }
        cout << arr[N-1] << endl;
    }
}
