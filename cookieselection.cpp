#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define vii vector<pair<int,int>>
#define ii pair<int, int>
#define ll long long
#define TC int t; cin >> t; while (t--)


#include <bits/extc++.h>
// pbds
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
            tree_order_statistics_node_update>
    ost;

int main(int argc, char const *argv[])
{
    string input;

    ost tree;
    int size = 0;
    int ord = 0;

    while (cin >> input) {

        if (input == "#") {

            ii output = (size % 2) ? (*tree.find_by_order((size+1)/2 - 1)) : (*tree.find_by_order(size/2));

            tree.erase(output);
            cout << output.first << endl;
            size--;
        }

        else {

            int k = stoi(input);
            tree.insert({k, ord++});
            size++;
        }
    }
}
