#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>

int main() {
    FAST

    int N;
    string word;
    int m;
    while (cin >> N && N) {
        int p1 = 0, p2 = 0;

        while (N--) {
            cin >> word >> m;

            if (word[0] == 'D') {
                p2 += m;
                cout << "DROP 2 " << m << endl; 
            }
            else {
                if (p1 >= m) {
                    p1 -= m;
                    cout << "TAKE 1 " << m << endl;
                }

                else {
                    if (p1 > 0) {
                        cout << "TAKE 1 " << p1 << endl;
                        m -= p1;
                    }
                    cout << "MOVE 2->1 " << p2 << endl; 
                    p1 = p2;
                    p2 = 0;

                    cout << "TAKE 1 " << m << endl;
                    p1 -= m;
                }
            }

        }
        cout << endl;
    }

}