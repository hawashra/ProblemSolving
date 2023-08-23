#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST                     \
    std::cin.tie(0);             \
    ios::sync_with_stdio(false); \
    std::cout.tie(0);
using namespace std;
#define min(a, b) (a < b) ? (a) : (b)
#define max(a, b) (a > b) ? (a) : (b)
#define vii vector<pair<int, int>>
#define ii pair<int, int>
#define ll long long

#define TC    \
    int t;    \
    cin >> t; \
    while (t--)

string strs[100000];
vector<queue<int>> queues(100000);


void solve()
{
    cout << "Hi";
}


void print(int idx) {

    cout << strs[idx];

    while (!queues[idx].empty()) {
        print(queues[idx].front());

        queues[idx].pop();
    }
}


int main(int argc, char const *argv[])
{
    FAST int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> strs[i];

    int a, b;
    bitset<100000> empty;
    empty.reset();

    for (int i = 0; i < N-1; i++)
    {
        cin >> a >> b;
        a-=1;
        b-=1;
        if (!empty.test(b))
        {
            empty.set(b);
            queues[a].push(b);
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (!empty.test(i))
        {
            print(i);

            break;
        }

    }
    return 0;
}
