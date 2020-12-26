/**
 * boj 12865 평범한 배낭
 * DP (Knapsack problem)
 */

#include <bits/stdc++.h>
using namespace std;

int N, K, W[101], V[101], knapsack[101][100001];

void solve()
{
    cin >> N >> K;
    for (int i=1; i<=N; ++i)
        cin >> W[i] >> V[i];
    for (int i=1; i<=N; ++i)
    {
        for (int j=0; j<=K; ++j)
        {
            if (W[i] > j)
                knapsack[i][j] = knapsack[i-1][j];
            else
                knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-W[i]] + V[i]);
        }
    }
    cout << knapsack[N][K];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}