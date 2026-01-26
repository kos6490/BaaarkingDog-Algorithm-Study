#include <bits/stdc++.h>

using namespace std;

int L, C;
char alphabet[20];
int ans[20];

void backtrack(int cur)
{
    if (cur == L)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < L; i++)
        {
            char ch = alphabet[ans[i]];

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }

        if (cnt1 >= 1 && cnt2 >= 2)
        {
            for (int i = 0; i < L; i++)
            {
                cout << alphabet[ans[i]];
            }

            cout << '\n';
        }

        return;
    }

    int start = 0;

    if (cur != 0)
    {
        start = ans[cur - 1] + 1;
    }

    for (int i = start; i < C; i++)
    {
        ans[cur] = i;

        backtrack(cur + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        cin >> alphabet[i];
    }

    sort(alphabet, alphabet + C);

    backtrack(0);
}