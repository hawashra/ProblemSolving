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
#define TC int t; cin >> t; while (t--)

void solve() {
    cout << "Hi"; 
}

unsigned W[1 << 15];
unsigned P[1 << 15]; // potencies for 0..2^N - 1 corcners. 

int main(int argc, char const *argv[])
{
    
    int N;
    int maxP, maxN, currP;
    while (cin >> N) {
        // weights
        memset(W, 0, sizeof(int) * (1<<N));
        memset(P, 0, sizeof(int) * (1<<N));

        for (int i = 0; i < 1<<N; i++) {
            cin >> W[i];
        }

        for (int i = 0; i < 1 << N; i++) {
            
            for (int j = 0; j < N; j++) {
                P[i] += W[i ^ (1 << j) ]; // add the weight of the j-th neighbour.
            }
        }

        // n = 2^N. 


        // O(n)
        maxP = 0;

        for (int i = 0; i < 1 << N; i++) {
            currP = P[i];
            maxN = 0;

            for (int j = 0; j < N; j++) {
                maxN = max(maxN, P[i ^ (1 << j)]);
            }

            maxP = max(maxP, maxN + currP);
        }

        cout << maxP << endl;
    }

    return 0;
}
