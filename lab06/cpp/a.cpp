#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // count how many times each letter appears
    int cnt[26] = {0};
    for (char c : s)
        cnt[c - 'a']++;

    // Albert's alphabet: vowels first, then consonants
    string order = "aeioubcdfghjklmnpqrstvwxyz";
    for (char c : order)
        for (int i = 0; i < cnt[c - 'a']; i++)
            cout << c;
}
