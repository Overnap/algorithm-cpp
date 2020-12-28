/**
 * boj 4149 Factoring Large Numbers
 * Factorize with Pollard's rho & Miller-Rabin (for ull)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

ull modmul(ull a, ull b, ull n)
{
    return ((unsigned __int128)a * b) % n;
}

//// if __int128 isn't available
//ull modmul(ull a, ull b, ull n)
//{
//    if (b == 0)
//        return 0;
//    if (b == 1)
//        return a;
//
//    ull t = modmul(a, b/2, n);
//    t = (t+t)%n;
//    if (b % 2)
//        t = (t+a)%n;
//    return t;
//}

ull modpow(ull a, ull d, ull n)
{
    if (d == 0)
        return 1;

    ull r = modpow(a, d/2, n);
    r = modmul(r, r, n);
    if (d % 2)
        r = modmul(r, a, n);
    return r;
}

ull gcd(ull a, ull b)
{
    return b ? gcd(b, a%b) : a;
}

bool is_prime(ull n)
{
    const ull as[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    // const ull as[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; // easier to remember
    auto miller_rabin = [] (ull n, ull a) -> bool
    {
        ull d = n-1, temp;
        while (d % 2 == 0)
        {
            d /= 2;
            temp = modpow(a, d, n);
            if (temp == n-1)
                return true;
        }
        return temp == 1;
    };

    for (ull a : as)
    {
        if (a >= n)
            break;
        if (!miller_rabin(n, a))
            return false;
    }
    return true;
}

void pollard_rho(ull n, vector<ull>& factors)
{
    if (n == 1)
        return;
    if (n % 2 == 0)
    {
        factors.push_back(2);
        pollard_rho(n/2, factors);
        return;
    }
    if (is_prime(n))
    {
        factors.push_back(n);
        return;
    }

    ull x, y, c = 1, g = 1;
    auto f = [n, &c] (ull x) -> ull { return (modmul(x, x, n) + c) % n; };
    y = x = 2;
    while (g == 1 || g == n)
    {
        if (g == n)
        {
            c = rand() % 123;
            y = x = rand() % (n-2) + 2;
        }

        x = f(x);
        y = f(f(y));
        g = gcd(n, y>x ? y-x : x-y);
    }

    pollard_rho(g, factors);
    pollard_rho(n / g, factors);
}

void solve()
{
    ull n;
    cin >> n;

    vector<ull> factors;
    pollard_rho(n, factors);
    sort(factors.begin(), factors.end());
    for (auto i : factors)
        cout << i << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}