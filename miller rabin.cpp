/**
 * boj 5615 아파트 임대
 * Miller-Rabin primality test (for uint)
 */

#include <iostream>

using namespace std;

unsigned modpow(unsigned a, unsigned d, unsigned n)
{
    if (d == 0)
        return 1;

    unsigned long long r = modpow(a, d/2, n);
    r = (r*r) % n;
    if (d % 2)
        r = (r*a) % n;
    return r;
}

bool miller_rabin(unsigned int n)
{
    unsigned d = n-1, s = 0;
    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }

    const unsigned as[3] = {2, 7, 61};
    for (auto a : as)
    {
        if (a >= n || modpow(a, d, n) == 1)
            continue;

        bool checked = false;
        for (int i=0; i<s; ++i)
        {
            if (modpow(a,d*modpow(2, i, n), n) == n-1)
            {
                checked = true;
                break;
            }
        }
        if (checked)
            continue;

        return false;
    }

    return true;
}

void solve()
{
    int N, result = 0;
    cin >> N;
    for (int i=0; i<N; ++i)
    {
        unsigned k;
        cin >> k;
        k = 2 * k + 1;

        result += miller_rabin(k);
    }
    cout << result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}