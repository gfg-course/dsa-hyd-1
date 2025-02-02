#include <bits/stdc++.h>
using namespace std;

bool isAlphaNumeric(char ch) {
    bool isUpperCase = (ch >= 'A' && ch <= 'Z');
    bool isLowerCase = (ch >= 'a' && ch <= 'z');
    bool isNumeric = (ch >= '0' && ch <= '9');

    return isUpperCase || isLowerCase || isNumeric;
}

bool isSame(char ch1, char ch2) {
    if (ch1 == ch2) {
        return true;
    }

    // Assuming ch1 to be uppercase and ch2 to be lowercase
    if (ch1 - 'A' + 'a' == ch2) {
        return true;
    }

    // Assuming ch1 to be lowercase and ch2 to be uppercase
    if (ch2 - 'A' + 'a' == ch1) {
        return true;
    }

    return false;
}

bool isSpecialPalindrome(string s) {

    int start = 0, end = s.length() - 1;
    while (start < end) {
        if (!isAlphaNumeric(s[start])) {
            start++;
        } else if (!isAlphaNumeric(s[end])) {
            end--;
        } else {
            if (!isSame(s[start], s[end])) {
                return false;
            }
            start++;
            end--;
        }
    }
    return true;
}

int main() {

    cout << isSpecialPalindrome("level") << endl;
    cout << isSpecialPalindrome("levels") << endl;
    cout << isSpecialPalindrome("race a car") << endl;
    cout << isSpecialPalindrome("A man: nama") << endl;
}