#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long
#define endl '\n'

#define TC int t; cin >> t; while (t--)

void solve() {
    cout << "Hi"; 
}

int main(int argc, char const *argv[])
{

    unordered_map<string, int> index;
    int count = 0;

    for (char a = 'a'; a <= 'z'; a++) {
        index[string(1, a)] = ++count;
    }

    for (char a = 'a'; a <= 'y'; a++) {
        for (char b = a+1; b <= 'z'; b++) {
            string x = string(1, a) + string(1, b);
            index[x] = ++count;
        }
    }

    for (char a = 'a'; a <= 'x'; a++) {
        for (char b = a+1; b <= 'y'; b++) {
            for (char c = b+1; c <= 'z'; c++) {
                string x = string(1, a) + string(1, b) + string(1, c);
                index[x] = ++count;
            }
        }
    }

    for (char a = 'a'; a <= 'w'; a++) {
        for (char b = a+1; b <= 'x'; b++) {
            for (char c = b+1; c <= 'y'; c++) {
                for (char d = c+1; d <= 'z'; d++) {
                    string x = string(1, a) + string(1, b) + string(1, c) + string(1, d);
                    index[x] = ++count;
                }
            }
        }
    }

    for (char a = 'a'; a <= 'v'; a++) {
        for (char b = a+1; b <= 'w'; b++) {
            for (char c = b+1; c <= 'x'; c++) {
                for (char d = c+1; d <= 'y'; d++) {
                    for (char e = d+1; e <= 'z'; e++) {
                        string x = string(1, a) + string(1, b) + string (1, c) + string(1, d) + string (1, e);
                        index[x] = ++count;
                    }
                }
            }
        }
    }


    string input; 
    while (cin >> input) {

        if (index.find(input) != index.end()) cout << index[input] << endl;
        else cout << 0 << endl;
    }

    return 0;
}
