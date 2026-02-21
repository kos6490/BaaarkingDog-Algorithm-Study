#include <bits/stdc++.h>

using namespace std;

int N, cnt, idx, maximum = -1e9 - 7, minimum = 1e9 + 7;
int A[12];
char op[11];
char sel[11];
char symbol[] = { '+', '-', '*', '/' };

void calc()
{
    int sum = A[0];

    for (int i = 1; i < N; i++)
    {
        if (sel[i - 1] == '+')
            sum += A[i];
        else if (sel[i - 1] == '-')
            sum -= A[i];
        else if (sel[i - 1] == '*')
            sum *= A[i];
        else if (sel[i - 1] == '/')
            sum /= A[i];
    }

    maximum = max(maximum, sum);
    minimum = min(minimum, sum);
}

void solve(int cur)
{
    if (cur >= N - 1)
    {
        calc();
        return;
    }

    char backup[11];
    memcpy(backup, op, sizeof(op));

    for (int i = 0; i < N - 1; i++)
    {
        if (op[i] != ' ')
        {
            sel[cur] = op[i];
            op[i] = ' ';
            solve(cur + 1);
            memcpy(op, backup, sizeof(backup));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < 4; i++)
    {
        cin >> cnt;

        for (int j = 0; j < cnt; j++)
            op[idx++] = symbol[i];
    }

    solve(0);

    cout << maximum << '\n'
         << minimum;
}