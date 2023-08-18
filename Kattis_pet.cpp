#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define endl "\n";

bool sortbysec(const pair<string,int> &a,
                const pair<string,int> &b);

int main() {
    
    int best = -1;
    int bestIdx = -1;
    int n1,n2,n3,n4,sum;
    for (int i = 0; i < 5; i++) {
        sum = 0;
        scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
        sum = n1 + n2 + n3 + n4;
        
        if (sum > best) {
            best = sum;
            bestIdx = i+1;
        }
    }
    
    cout << bestIdx << " " << best;
    
}