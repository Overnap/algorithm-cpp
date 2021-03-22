/**
 * boj 1197 최소 신장 트리
 * Prim's algorithm
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> edges(V);
    for (int i=0; i<E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }

    vector<int> memo(V, 1e9);
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 0);

    while (!pq.empty())
    {
        const int cost = -pq.top().first, index = pq.top().second;
        pq.pop();

        if (memo[index] != 1e9)
            continue;
        memo[index] = cost;
        for (auto& p : edges[index])
        {
            if (memo[p.first] == 1e9)
                pq.emplace(-p.second, p.first);
        }
    }

    ll answer = 0;
    for (int i : memo)
        answer += i;
    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}