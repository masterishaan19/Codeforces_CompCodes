#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll NthFibNumber(ll num)
{
    ll a = 1, b = 1;
    for (int i = 2; i <= num; i++)
    {
        ll temp = a + b;
        a = b;
        b = temp;
    }
    // cout << b << endl;
    return b;
}
int main()
{
    ll num;
    cin >> num;
    cout << NthFibNumber(num) << endl;
}