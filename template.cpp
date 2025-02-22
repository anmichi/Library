#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <class T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using pbds_mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pbds_trie = trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;
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
template <class T>
inline void compress(vector<T> &a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}
struct linear_sieve {
    vector<int> least_factor, prime_list;
    linear_sieve(int n) : least_factor(n + 1, 0) {
        for (int i = 2; i <= n; i++) {
            if (least_factor[i] == 0) {
                least_factor[i] = i;
                prime_list.push_back(i);
            }
            for (int p : prime_list) {
                if (ll(i) * p > n || p > least_factor[i]) break;
                least_factor[i * p] = p;
            }
        }
    }
};
ll extgcd(ll a, ll b, ll &x, ll &y) {
    // ax+by=gcd(|a|,|b|)
    if (a < 0 || b < 0) {
        ll d = extgcd(abs(a), abs(b), x, y);
        if (a < 0) x = -x;
        if (b < 0) y = -y;
        return d;
    }
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
template <typename T, typename U>
inline istream &operator>>(istream &is, pair<T, U> &rhs) {
    return is >> rhs.first >> rhs.second;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
    for (auto &e : v) is >> e;
    return is;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto itr = v.begin(), end_itr = v.end(); itr != end_itr;) {
        os << *itr;
        if (++itr != end_itr) os << " ";
    }
    return os;
}
