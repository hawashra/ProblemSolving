#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long

#define endl "\n";
#define TC int t; cin >> t; while (t--)

void solve() {

    int n, m;
    cin >> n >> m;
    bool can = true;
    int number;
    int arr[n][m];

    int colCnt = 0;

    for (int i=  0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int g[10][10] = {}, x, y;

    for (int j = 0; j < m && can; j++) {
        colCnt = 0;
        for (int i = 0; i < n;i++) {

            if (arr[i][j] == 1) {
                if (colCnt == 0) x = i;
                else y = i;
                colCnt++;
            }
        }

        if (colCnt != 2)
            can = false;   
        
        else {   
            if (g[x][y]) can = false;
            else g[x][y] = g[y][x] = 1;
        }
    }

    cout << ((can) ? "Yes" : "No") << endl;
}

int main(int argc, char const *argv[])
{
    TC {
        solve();
    }
    return 0;
}
