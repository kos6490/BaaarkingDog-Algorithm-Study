#include <bits/stdc++.h>

using namespace std;

string str;
string prefix[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < str.size(); i++)
        prefix[i] = str.substr(i, str.size());

    sort(prefix, prefix + str.size());

    for (int i = 0; i < str.size(); i++)
        cout << prefix[i] << '\n';
}