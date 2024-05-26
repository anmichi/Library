#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
template <class T, class U>
inline bool chmax(T &a, U b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T, class U>
inline bool chmin(T &a, U b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
constexpr int INF = 1000000000;
constexpr int64_t llINF = 3000000000000000000;
constexpr double eps = 1e-10;
const double pi = acos(-1);
vector<int> calc_factor(int n) {
    vector<int> least_factor(n + 1, 0), prime_list;
    for (int i = 2; i <= n; i++) {
        if (least_factor[i] == 0) {
            least_factor[i] = i;
            prime_list.push_back(i);
        }
        for (int j = 0; j < (int)prime_list.size() && i * prime_list[j] <= n; j++) {
            least_factor[i * prime_list[j]] = prime_list[j];
            if (prime_list[j] == least_factor[i]) break;
        }
    }
    return least_factor;
}
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b >>= 1;
    }
    return res;
}