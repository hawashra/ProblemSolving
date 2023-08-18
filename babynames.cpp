#include <iostream>
#include <string>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define TC int t; cin >> t; while (t--)

// ChatGPT improvement of the code I submitted first on Kattis.
// GPT says that fenwick tree can be used, and it is faster (I didn't prove it). 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int op;
    string bbname;
    int gender; // 1 male | 2 female

    tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> males;
    tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> females;

    string start, end;

    while (cin >> op && op) {
        if (op == 1) {
            cin >> bbname >> gender;
            if (gender == 1) males.insert(bbname);
            else females.insert(bbname);
        } else if (op == 2) {
            cin >> bbname;
            males.erase(bbname);
            females.erase(bbname);
        } else {
            int count = 0;
            cin >> start >> end >> gender;

            int male_count = males.order_of_key(end) - males.order_of_key(start);
            int female_count = females.order_of_key(end) - females.order_of_key(start);

            if (gender == 1)
                count = male_count;
            else if (gender == 2)
                count = female_count;
            else
                count = male_count + female_count;

            cout << count << '\n';
        }
    }
    return 0;
}
