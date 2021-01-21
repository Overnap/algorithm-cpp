/**
 * boj 1753 최단경로
 * Dijkstra
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve()
{
    int V, E, start;
    cin >> V >> E >> start;
    vector<vector<pair<int, int>>> edges(V);
    for (int i=0; i<E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[u].emplace_back(v, w);
    }
    vector<int> dp(V, 1e9);
    dp[start-1] = 0;
    auto comp = [] (auto& a, auto& b) { return a.second > b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
    pq.emplace(start-1, 0);
    while (!pq.empty())
    {
        const int origin = pq.top().first;
        if (pq.top().second == dp[origin])
        {
            for (auto& p : edges[origin])
            {
                if (dp[p.first] > dp[origin] + p.second)
                {
                    dp[p.first] = dp[origin] + p.second;
                    pq.emplace(p.first, dp[p.first]);
                }
            }
        }
        pq.pop();
    }
    for (int i : dp)
        cout << (i == 1e9 ? "INF" : to_string(i)) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}