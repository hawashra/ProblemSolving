#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define endl "\n";

bool sortbysec(const pair<string,int> &a,
                const pair<string,int> &b);

int main() {
    int T;
    scanf("%d\n", &T);
    int n,m,l, a, b, N, cost, lower;
    vector<pair<string,int>> vect;
    char name[20];
    string temp;
    string str_name;
    for (int i = 1; i <= T; i++) {
        vect.clear();
        scanf("%d %d %d\n", &n, &m, &l);
        while (l--) {
            N = n;
            getline(cin, str_name, ':');
            cin >> a;
            cin.ignore();
            cin >> b;
            cin.ignore();
            cost = 0;
            
            while (N >= 2*m) {

                if (b < ((N+1)/2)*a) {
                    N >>= 1;
                    cost += b;
                }
                else {
                    break;
                }
            }

            cost = cost + (N - m)*a;
            vect.push_back(make_pair(str_name, cost+0));
        }

        sort(ALL(vect),sortbysec);

        std::printf("Case %d\n", i);

        for (auto elem : vect) {
            cout << elem.first << " " << elem.second << endl;
        }
    }

}

bool sortbysec(const pair<string,int> &a,
                const pair<string,int> &b)
{
    return (a.second < b.second);
}