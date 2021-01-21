/**
 * boj 11404 플로이드
 * Floyd-Warshall
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> bus(N, vector<int>(N, 1e9));
    for (int i=0; i<N; ++i)
        bus[i][i] = 0;
    for (int i=0; i<M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bus[a-1][b-1] = min(c, bus[a-1][b-1]);
    }
    for (int k=0; k<N; ++k)
    {
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<N; ++j)
                    bus[i][j] = min(bus[i][k] + bus[k][j], bus[i][j]);
        }
    }

    for (int i=0; i<N; ++i)
    {
        cout << (bus[i][0] == 1e9 ? 0 : bus[i][0]);
        for (int j=1; j<N; ++j)
            cout << ' ' << (bus[i][j] == 1e9 ? 0 : bus[i][j]);
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}