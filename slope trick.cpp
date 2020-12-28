/**
 * boj 13323 BOJ 수열 1
 * slope trick
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve()
{
    int N;
    vector<int> A;

    cin >> N;
    A.resize(N);
    for (int i=0; i<N; ++i)
        cin >> A[i];

    priority_queue<int> pq;
    long long answer = 0;

    pq.push(A[0]);
    for (int i=1; i<N; ++i)
    {
        int end = pq.top() + i;
        if (A[i] < end)
        {
            pq.pop();
            pq.push(A[i] - i);
            answer += end - A[i];
        }
        pq.push(A[i] - i);
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}