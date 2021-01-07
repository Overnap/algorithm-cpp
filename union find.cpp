/**
 * boj 4195 Virtual Friends
 * Union & Find (Merge & Find)
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int parent[200000], union_size[200000], count;
unordered_map<string, int> index_array;

int get_index(string& name)
{
    if (index_array.count(name) == 0)
        return index_array[name] = count++;
    else
        return index_array[name];
}

int find(int i)
{
    if (i == parent[i])
        return i;

    return parent[i] = find(parent[i]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        parent[x] = y;
        union_size[y] += union_size[x];
    }
}

void solve()
{
    int F;
    cin >> F;

    count = 0;
    for (int i=0; i<2*F; ++i)
    {
        parent[i] = i;
        union_size[i] = 1;
    }
    for (int i=0; i<F; ++i)
    {
        string n1, n2;
        cin >> n1 >> n2;
        merge(get_index(n1), get_index(n2));
        cout << union_size[find(get_index(n1))] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}