#include <bits/stdc++.h>
using namespace std;

bool isSame(char cl, char op) {
    return 
        (op == '(' && cl == ')') ||
        (op == '{' && cl == '}') ||
        (op == '[' && cl == ']');
}

// TC: O(n)
// AS: O(n)
bool isBalanced(string s) {

    stack<char> helper;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            helper.push(s[i]);
        } else {
            if (helper.empty() || !isSame(s[i], helper.top())) {
                return false;
            }
            helper.pop();
        }
    }

    return helper.empty();
}

int main() { 
}