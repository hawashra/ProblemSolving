#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>

int main() {
    FAST
    int n;
    cin >> n;
    int k = 2*n;
    queue<int> pile1;
    
    for (int i = 0; i < k; i++)  {
        int num; 
        cin >> num;
        pile1.push(num);
    }

    int ans = 0;
    stack<int> pile2;


    while (!pile1.empty()) {
        ans++;

        if (!pile2.empty() && pile2.top() == pile1.front()) { pile1.pop(); pile2.pop(); }
        else { pile2.push(pile1.front()); pile1.pop(); }
    }

    if (pile1.empty() && pile2.empty()) cout << ans << endl;
    else cout << "impossible" << endl;
    
}