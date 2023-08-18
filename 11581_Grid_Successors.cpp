#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long

#define TC int t; cin >> t; while (t--)


int main(int argc, char const *argv[])
{

    int tc;
    cin >> tc;
    int g[3][3];
    string line;

    while (tc--) {
        getline(cin, line);
        int zer = 0;
        for (int i = 0; i < 3; i++) {
            cin >> line;
            for (int j = 0; j < 3; j++) {
                g[i][j] = line[j] - '0';
                if (line[j] == '0') zer++;
            }
        }


        int f[3][3];

        int count = -1;
        bool go = true;

        // if g is all zeros (special case)

        if (zer == 9) go = false;
        

        while (go) {
            zer = 0;
            count++;
            for (int i = 0; i < 3 && go; i++) {
                for (int j = 0; j < 3 && go; j++) {
                    f[i][j] = 0;
                    int s = 0;

                    if (i+1 < 3) s+= g[i+1][j];
                    if (i-1 >= 0) s+= g[i-1][j];
                    if (j+1 < 3) s+= g[i][j+1];
                    if (j-1 >=0) s+= g[i][j-1];

                    // if there is a one and all its neighbours are zeros.
                    // it will always give the same array.
                    if (s == 0 && f[i][j] == 1) {
                        count = -1;
                        go = false;
                    }

                    s=s%2;

                    f[i][j] = s;

                    if (f[i][j] == 0) zer++;
                }
            }

            // all zeros 
            if (zer == 9 || !go) break;

            // now g is previous f
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    g[i][j] = f[i][j];
                }
            }
        }

        cout << count << endl;
    }


    return 0;
}
