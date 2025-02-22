#include <bits/stdc++.h>
using namespace std;

string getHashKey(string &s) {

    vector<int> freq(26, 0);
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }

    string hashKey = "";
    for (int i = 0; i < 26; i++) {
        hashKey.append(to_string(freq[i]));
        hashKey.append("#");
    }

    return hashKey;
}

/**
 * TC: O(n*m) 
 * AS: O(n*m)
 * 
 * where n = number of strings
 * and m = max length of any string.
 * */
vector<vector<string>> groupAnagrams(vector<string> arr) {

    unordered_map<string, vector<string>> hash;

    for (int i = 0; i < arr.size(); i++) {
        string hashKey = getHashKey(arr[i]);
        // If this key has not been seen before, initialize the empty array.
        if (hash.find(hashKey) == hash.end()) { 
            hash[hashKey] = {};  
        } 
        hash[hashKey].push_back(arr[i]);
    }

    vector<vector<string>> result;
    for (auto it = hash.begin(); it != hash.end(); ++it) {
        result.push_back(it->second);
    }

    return result;
}


int main() {
    vector<vector<string>> res = groupAnagrams({"act", "god", "cat", "dog", "tac"});
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}