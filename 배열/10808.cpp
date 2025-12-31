#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int alphabet[26] = {};

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        alphabet[s[i] - 'a'] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << ' ';
    }

    return 0;
}