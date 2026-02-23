#include <bits/stdc++.h>

using namespace std;

int N;
string word[20001];

bool cmp(string &a, string &b)
{
    if (a.length() == b.length())
        return a < b;

    return a.length() < b.length();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> word[i];

    sort(word, word + N, cmp);

    for (int i = 0; i < N - 1; i++)
        if (word[i] == word[i + 1])
            word[i] = "";

    for (int i = 0; i < N; i++)
        if (word[i] == "")
            continue;
        else
            cout << word[i] << '\n';
}