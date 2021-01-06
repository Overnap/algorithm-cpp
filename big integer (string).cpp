/**
 * boj 10757 큰 수 A+B
 * Big Integer (String)
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct bigint_str
{
    string num;

    bigint_str() = default;
    bigint_str(string s) : num(std::move(s)) {}

    void operator += (const bigint_str& other)
    {
        string other_num = other.num;
        reverse(num.begin(), num.end());
        reverse(other_num.begin(), other_num.end());

        bool quotient = false;
        for (int i=0; i<num.size() || i<other_num.size() || quotient; ++i)
        {
            if (i >= num.size())
                num.push_back('0');
            if (i < other_num.size())
                num[i] += other_num[i] - '0';
            if (quotient)
            {
                num[i]++;
                quotient = false;
            }
            if (num[i] > '9')
            {
                num[i] -= 10;
                quotient = true;
            }
        }

        reverse(num.begin(), num.end());
    }
};

void solve()
{
    bigint_str A, B;
    cin >> A.num >> B.num;
    A += B;
    cout << A.num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}