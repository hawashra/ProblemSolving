#include <bits/stdc++.h> // here we have all the STL we need, including istringstream and ostringstream
#define ALL(x) x.begin(), x.end()
#define FAST std::cin.tie(0); ios::sync_with_stdio(false); std::cout.tie(0);
using namespace std;
#define min(a,b) (a < b) ? (a) : (b)
#define max(a,b) (a > b) ? (a) : (b)
#define vii vector<pair<int,int>>
bool isOpenningBracket(char c);
bool isClosingBracket(char c);

int main() {

    string input;


    while (cin >> input) {
        int len = input.length(), i;
        stack<char> match; 
        int count = 0;

        for (i = 0; i < len; i++) {
            count++;

            if (isOpenningBracket(input[i])) {
                
                if (i+1 < len && input[i+1] == '*' && input[i] == '(') {
                    match.push('*');
                    i++;
                }

                else
                    match.push(input[i]);
            }

            else if (isClosingBracket(input[i]) || (input[i] == '*' && i+1 < len && input[i+1] == ')')) {

                if (match.empty()) {
                    break;
                }

                char top = match.top();

                if (input[i] == '*' && i+1 < len && input[i+1] == ')' && top == '*') {
                    match.pop();
                    i++;
                }

                else if (top == '(' && input[i] == ')') match.pop();

                else if (top == '{' && input[i] == '}') match.pop();

                else if (top == '[' && input[i] == ']') match.pop();

                else if (top == '<' && input[i] == '>') match.pop();

                else {
                    break;
                }
            }
        }

        if (i < len || !match.empty()) {
            if (i >= len) count++;
            cout << "NO " << count << endl;
        }

        else cout << "YES" << endl;

        while (!match.empty()) match.pop();
    }

}

bool isOpenningBracket(char c) {
    return (c == '{' || c == '[' || c == '(' || c == '<');
}

bool isClosingBracket(char c) {
    return (c == '}' || c == ']' || c == ')' || c == '>');
}