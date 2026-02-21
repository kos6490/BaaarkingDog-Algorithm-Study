#include <bits/stdc++.h>

using namespace std;

int N, arr[1000001], temp[1000001];

void merge(int start, int end)
{
    int idx = start, mid = (start + end) / 2;
    int left_idx = start, right_idx = mid;

    while (left_idx < mid && right_idx < end)
        if (arr[left_idx] <= arr[right_idx])
            temp[idx++] = arr[left_idx++];
        else if (arr[left_idx] > arr[right_idx])
            temp[idx++] = arr[right_idx++];

    if (left_idx >= mid)
        while (right_idx < end)
            temp[idx++] = arr[right_idx++];
    else
        while (left_idx < mid)
            temp[idx++] = arr[left_idx++];

    for (int i = start; i < end; i++)
        arr[i] = temp[i];
}

void mergeSort(int start, int end)
{
    if (end - start == 1)
        return;

    int mid = (start + end) / 2;

    mergeSort(start, mid);
    mergeSort(mid, end);
    merge(start, end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    mergeSort(0, N);

    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';
}