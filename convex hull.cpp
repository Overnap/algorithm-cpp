/**
 * boj 7420 Wall
 * Convex hull
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point
{
    int x, y, p, q;

    void input()
    {
        cin >> x >> y;
        p = q = 0;
    }

    bool operator<(const point& other)
    {
        if (1LL * p * other.q != 1LL * q * other.p)
            return 1LL * p * other.q > 1LL * q * other.p;
        else if (y != other.y)
            return y < other.y;
        else
            return x < other.x;
    }
};

bool ccw(const point& a, const point& b, const point& c)
{
    return 1LL * (b.x - a.x) * (c.y - b.y) > 1LL * (b.y - a.y) * (c.x - b.x);
}

void solve()
{
    int N, L;
    cin >> N >> L;

    vector<point> v(N);
    for (int i=0; i<N; ++i)
        v[i].input();

    swap(v[0], *min_element(v.begin(), v.end()));
    for(int i=1; i<N; ++i)
    {
        v[i].p = v[i].x - v[0].x;
        v[i].q = v[i].y - v[0].y;
    }
    sort(v.begin()+1, v.end());

    vector<point> hull;
    for (int i=0; i<N; ++i)
    {
        while (hull.size() >= 2 && !ccw(hull[hull.size()-2], hull.back(), v[i]))
            hull.pop_back();
        hull.push_back(v[i]);
    }

    auto dist = [] (const point& a, const point& b) -> double
    {
        return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y));
    };
    double length = 0;
    for (int i=0; i<hull.size()-1; ++i)
        length += dist(hull[i], hull[i+1]);
    length += dist(hull[0], hull.back());
    length += 2.0 * M_PI * L;

    cout << round(length);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}