#include <bits/stdc++.h>
using namespace std;

/**
 * T(N) = T(N - 1) + 3^N
 * 
 * AS: O(3^N)
 * */

vector<string> keyPad = {"", "", "abc", 
                        "def", "ghi", "jkl", 
                        "mno", "pqrs", "tuv", "wxyz"};

vector<string> possibleWordsUtil(vector<int> &arr, int n) {
    if (n == 0) {
        return {""};
    }

    vector<string> subResult = possibleWordsUtil(arr, n - 1);
    int digit = arr[n - 1];

    vector<string> result;
    for (string s : subResult) {
        for (char ch : keyPad[digit]) {
            string current = s;
            current.push_back(ch);
            result.push_back(current);
        }
    }

    return result;
}

vector<string> possibleWords(vector<int> arr) {

    return possibleWordsUtil(arr, arr.size());
}

int main() {
    vector<string> result = possibleWords({2, 3});
    for (string s : result) {
        cout << s << endl;
    }
}