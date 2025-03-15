#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
string firstNonRepeatingInStream(string s) {

    string result = "";
    queue<char> q;
    vector<int> freq(26, 0);

    for (int i = 0; i < s.length(); i++) {

        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] == 1) {
            q.push(s[i]);
        }

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            result.push_back('#');
        } else {
            result.push_back(q.front());
        }
    }

    return result;
}

int main() { 
    cout << firstNonRepeatingInStream("aabcb") << endl;
    cout << firstNonRepeatingInStream("aaaa") << endl;
    cout << firstNonRepeatingInStream("abcd") << endl;
}