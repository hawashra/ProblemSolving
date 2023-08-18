#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define endl "\n"

// WTF??? why WA?? the idea is 100% valid and I saw the same code in Java it gives AC!!!.

int main() {

    FAST

    int N;
    string s1, s2;
    scanf("%d", &N);
    getchar(); // Clear the newline character
    getline(cin, s1);
    getline(cin, s2);    
    bool suc = true;

    if (N % 2 == 0) {
        suc = (s1 == s2);
    }
    else {

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[i]) {
                suc = false;
                break;
            }
        }
    }

    if (suc) cout << "Deletion succeeded" << endl;
    else cout << "Deletion failed" << endl;
}