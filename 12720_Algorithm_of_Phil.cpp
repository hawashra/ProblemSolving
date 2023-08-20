#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long
#define endl "\n"
#define MOD 1000000007

#define TC int t; cin >> t; while (t--)

void solve() {
    cout << "Hi"; 
}

// x^y (mod p) (stolen from geeks for geeks)
// O(log y)
int power(long long x, unsigned int y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


int main(int argc, char const *argv[])
{

    string a;
    int len = 0;
    ll ans = 0;
    int left, right;
    int p;
    int tc = 0;
    TC {
        ++tc;
        cin >> a;
        len = a.size();
        p = len-1;
        ans = 0;
        right = len / 2;
        left = right - 1;


        if (len % 2 == 1) {

            int mid = len/2;
            ans = (ans + (power((a[mid] - '0')*2, p, MOD) % MOD)) % MOD; 
            p -= 1;

            left = mid-1;
            right = mid+1;
        }

        while (left >= 0 && right <= len-1) {

            ans = (ans + power(2*(max(a[left] - '0', a[right] - '0')), p, MOD)) % MOD;
            p -= 1;
            ans = (ans + power(2*(min(a[left] - '0', a[right] - '0')), p, MOD)) % MOD;

            left -= 1;
            right += 1;
            p -= 1;
        }
        
        cout << "Case #" << tc << ": " << (ans % MOD) << endl;
    }


    return 0;
}
