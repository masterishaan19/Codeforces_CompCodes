#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Binary Indexed Tree (Fenwick Tree)
struct BIT {
    vector<ll> bit;
    int n;

    BIT(int n) {
        this->n = n + 2;
        bit.assign(this->n, 0);
    }

    void update(int idx, ll val) {
        for (; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    ll query(int idx) {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    ll rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v) cin >> x;

    // Coordinate compression
    vector<ll> temp = v;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    unordered_map<ll, int> compress;
    for (int i = 0; i < temp.size(); i++)
        compress[temp[i]] = i + 1; // +1 to avoid index 0 in BIT

    // Compressed array
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = compress[v[i]];

    // Calculate suffix counts of elements smaller than current
    BIT bit_right(temp.size());
    vector<ll> rightSmaller(n);
    for (int i = n - 1; i >= 0; i--) {
        rightSmaller[i] = bit_right.query(arr[i] - 1); // elements < arr[i]
        bit_right.update(arr[i], 1);
    }

    // Reset and process left side using BIT
    BIT bit_left(temp.size());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll leftGreater = bit_left.query(temp.size()) - bit_left.query(arr[i]); // elements > arr[i]
        ans += leftGreater * rightSmaller[i];
        bit_left.update(arr[i], 1);
    }

    cout << ans << "\n";
    return 0;
}
