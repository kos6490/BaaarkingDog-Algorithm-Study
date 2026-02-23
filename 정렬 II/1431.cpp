#include <bits/stdc++.h>

using namespace std;

int N;
string serial[51];

int cal(string tmp)
{
    int sum = 0;

    for (char ch : tmp)
        if (ch >= '0' && ch <= '9')
            sum += ch - '0';

    return sum;
}

bool cmp(string a, string b)
{
    if (a.length() == b.length())
        if (cal(a) == cal(b))
            return a < b;
        else
            return cal(a) < cal(b);
    else
        return a.length() < b.length();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> serial[i];

    sort(serial, serial + N, cmp);

    for (int i = 0; i < N; i++)
        cout << serial[i] << '\n';
}