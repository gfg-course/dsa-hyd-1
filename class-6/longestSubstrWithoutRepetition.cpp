#include <bits/stdc++.h>
using namespace std;

/**
 * TC: O(n)
 * AS: O(1)
 * */
int longestSubstrWithoutRepititon(string s) {

    int result = 0;
    int left = 0, right = 0;
    int n = s.length();

    vector<bool> isPresent(26, false);

    while (right < n) {
        // If the current character is not present in the current substring,
        // then simply include it.
        if (!isPresent[s[right] - 'a']) {
            isPresent[s[right] - 'a'] = true;
            result = max(result, right - left + 1);
        }
        // Otherwise, we squeeze the string from the left to exclude the 
        // previous occurrence of this character.
        else {
            while (s[left] != s[right]) {
                isPresent[s[left] - 'a'] = false;
                left++;
            }
            left++;
        }

        right++;
    }

    return result;
}


int main() {
    cout << longestSubstrWithoutRepititon("geeksforgeeks") << endl;
    cout << longestSubstrWithoutRepititon("aaa") << endl;
}