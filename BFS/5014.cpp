#include <bits/stdc++.h>

using namespace std;

int area[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int F, S, G, U, D, count = 0;

    cin >> F >> S >> G >> U >> D;

    fill(area, area + 1000001, -1);

    queue<int> q;
    int UD[] = { U, -D };

    q.push(S);

    area[S] = 0;

    while (q.size())
    {
        int cur = q.front();

        q.pop();

        for (int i = 0; i < 2; i++)
        {
            int nud = cur + UD[i];

            if (nud < 1 || nud > F)
            {
                continue;
            }

            if (area[nud] != -1)
            {
                continue;
            }

            q.push(nud);

            area[nud] = area[cur] + 1;
        }
    }

    if (area[G] == -1)
    {
        cout << "use the stairs";
    }
    else
    {
        cout << area[G];
    }
}