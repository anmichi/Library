#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr int INF = 1001001001;
constexpr ll llINF = 3000000000000000010;
constexpr ld PI = 3.14159265358979323846;
constexpr ll dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
constexpr ll dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) (v).begin(), (v).end()
#define SUM(v) reduce(all(v))
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SORT(a) sort(all(a))
#define REV(a) reverse(all(a))
#define UNIQUE(a) SORT(a), a.erase(unique(all(a)), a.end())
#define SZ(a) int(a.size())
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define popcnt(x) (__builtin_popcountll((unsigned long long)(x)))

#include <bits/extc++.h>
using namespace __gnu_pbds;
template <class T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T, class U>
inline bool chmax(T& a, U b) {
    return (a < b ? a = b, 1 : 0);
}
template <class T, class U>
inline bool chmin(T& a, U b) {
    return (a > b ? a = b, 1 : 0);
}
ll llpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
template <class T, class U, class V>
T modpow(T a, U b, V m) {
    T res = 1 % m;
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
constexpr ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}
constexpr ll safe_div(ll x, ll m) {
    assert(m > 0);
    if (x % m && x < 0) return x / m - 1;
    return x / m;
}

inline int lsb(const ll& a) { return a ? __builtin_ctzll(a) : 64; }
inline int msb(const ll& a) { return a ? 63 - __builtin_clzll(a) : -1; }
constexpr ll mask(int n) { return (1LL << n) - 1; }
inline int test(const ll& x, int i) { return (x >> i) & 1; }
template <class T>
T rand(T l, T r) {
    static mt19937 mt(random_device{}());
    // [l, r)
    if constexpr (is_integral_v<T>) {
        return uniform_int_distribution<T>(l, r - 1)(mt);
    } else if constexpr (is_floating_point_v<T>) {
        return uniform_real_distribution<T>(l, r)(mt);
    }
}

template <typename T, typename U>
inline istream& operator>>(istream& is, pair<T, U>& rhs) {
    return is >> rhs.first >> rhs.second;
}
template <typename T>
inline istream& operator>>(istream& is, vector<T>& v) {
    for (auto& e : v) is >> e;
    return is;
}
template <typename T, typename U>
inline ostream& operator<<(ostream& os, const pair<T, U>& rhs) {
    return os << rhs.first << " " << rhs.second;
}
template <typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto itr = v.begin(), end_itr = v.end(); itr != end_itr;) {
        os << *itr;
        if (++itr != end_itr) os << " ";
    }
    return os;
}

template <class... Args>
void DUMP(Args&&... args) {
    ((cout << args << " "), ...);
    cout << endl;
}
#ifdef LOCAL
#define DBG(...)              \
    {                         \
        cout << #__VA_ARGS__; \
        cout << " : ";        \
        DUMP(__VA_ARGS__);    \
    }
#else
#define DBG(...) void(0);
#endif
void solve() {}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (1) solve();
}