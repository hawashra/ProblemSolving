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

void solve() {
    cout << "Hi"; 
}

int ands[230][256];

#define M (1 << 8) - 1 // 

int main(int argc, char const *argv[])
{

    for (int i= 0; i < 230; i++) {
        for (int j = 0; j < 256; j++) {
            ands[i][j] = i & j;
        }
    }

    unordered_map<int, int> cache;
    
    int n, q, a;
    int ans = 0;
    TC {
    
        cin >> n >> q;
        int x[n];

        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        for (; q--;) {
            ans = 0;
            cin >> a;

            if (cache.find(a) != cache.end()) {
                ans = cache[a];
            }
            else {
                for (int i = 0; i < n; i++) 
                    ans = max(ans, ands[a][x[i]&M]);

                cache[a] = ans;
            }
            
            cout << ans << endl;
        }
    }


    return 0;
}
