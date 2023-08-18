#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>
#define ii pair<int, int>

int main() {
    
    string trash;
    int id, val;
    string s;
    priority_queue<ii> pq;
    unordered_map<int, int> periods;
    while (getline(cin, s) , s[0] != '#') {
        istringstream iss (s);
        iss >> trash >> id >> val;
        
        periods[id] = val;
        ii p = make_pair(-val, id); // pushing the negative value to make it act as a min_heap. 
        
        pq.emplace(p);
    }

    int k;
    cin >> k;
    int temp;
    vector<int> equals; // if more than one process has the same value, we sort them by id and get what we want.
    while (true) {

        temp = pq.top().first; // (period initially), we add period to it each time we pop it, and then push it back. 
        //cout << "First " << temp << endl; 
        id = pq.top().second; // the id, doesn't change.
        //cout << "Second " << val << endl;
        equals.emplace_back(id); // put the id in there. 
        pq.pop();
        
        while ( !pq.empty() && pq.top().first == temp ) {
            equals.push_back(pq.top().second);
            pq.pop();
        }

        sort( ALL( equals ) ); // more than one id has same val, we sort them and print as much as we want, decreasing k. 

        int y = min(equals.size(), k); // to loop that much, we don't want to go out of bounds of the vector. 

        for (int i = 0; i < y; i++) {
            k--;
            cout << equals[i] << endl;
        }

        if (k == 0) {
            equals.clear();
            break;
        }

        for (int i = 0; i < equals.size(); i++) {
            pq.push(make_pair(temp-periods[equals[i]], equals[i]));
        }

        equals.clear();
    }
}