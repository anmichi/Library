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
using ll = long long;
template <class T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using pbds_mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pbds_trie = trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;

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
constexpr ll floor_div(ll x, ll m) {
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
template <int modulo>
struct modint {
    int x;
    modint() : x(0) {}
    modint(int64_t y) : x(y >= 0 ? y % modulo : (modulo - (-y) % modulo) % modulo) {}
    modint& operator+=(const modint& p) {
        if ((x += p.x) >= modulo) x -= modulo;
        return *this;
    }
    modint& operator-=(const modint& p) {
        if ((x += modulo - p.x) >= modulo) x -= modulo;
        return *this;
    }
    modint& operator*=(const modint& p) {
        x = (int)(1LL * x * p.x % modulo);
        return *this;
    }
    modint& operator/=(const modint& p) {
        *this *= p.inv();
        return *this;
    }
    modint operator-() const { return modint(-x); }
    modint operator+(const modint& p) const { return modint(*this) += p; }
    modint operator-(const modint& p) const { return modint(*this) -= p; }
    modint operator*(const modint& p) const { return modint(*this) *= p; }
    modint operator/(const modint& p) const { return modint(*this) /= p; }
    bool operator==(const modint& p) const { return x == p.x; }
    bool operator!=(const modint& p) const { return x != p.x; }
    modint inv() const {
        int a = x, b = modulo, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }
    modint pow(int64_t n) const {
        modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend ostream& operator<<(ostream& os, const modint& p) { return os << p.x; }
    friend istream& operator>>(istream& is, modint& a) {
        int64_t t;
        is >> t;
        a = modint<modulo>(t);
        return (is);
    }
    int val() const { return x; }
    static constexpr int mod() { return modulo; }
    static constexpr int half() { return (modulo + 1) >> 1; }
};
ll extgcd(ll a, ll b, ll& x, ll& y) {
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
template <class T>
struct binom_table {
    vector<T> fact;
    vector<vector<T>> C;
    binom_table(int n) : fact(n + 1), C(n + 1, vector<T>(n + 1, T(0))) {
        C[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    }
};
template <typename T>
struct Binomial {
    vector<T> inv, fact, factinv;
    Binomial(int n) {
        inv.resize(n + 1);
        fact.resize(n + 1);
        factinv.resize(n + 1);
        inv[0] = fact[0] = factinv[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        factinv[n] = fact[n].inv();
        inv[n] = fact[n - 1] * factinv[n];
        for (int i = n - 1; i >= 1; i--) {
            factinv[i] = factinv[i + 1] * (i + 1);
            inv[i] = fact[i - 1] * factinv[i];
        }
    }
    T C(int n, int r) {
        if (n < 0 || n < r || r < 0) return 0;
        return fact[n] * factinv[n - r] * factinv[r];
    }
    T P(int n, int r) {
        if (n < 0 || n < r || r < 0) return 0;
        return fact[n] * factinv[n - r];
    }
    T H(int n, int r) {
        if (n == 0 && r == 0) return 1;
        if (n < 0 || r < 0) return 0;
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};
template <class T = int, bool Directed = false>
struct Graph {
    struct Edge {
        int from, to, idx;
        T cost;
        operator int() const { return to; }
    };
    vector<vector<Edge>> g;
    int es;
    Graph() = default;
    explicit Graph(int n) : g(n), es(0) {}
    int size() const { return int(g.size()); }
    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, es, cost);
        g[to].emplace_back(to, from, es, cost);
        es++;
    }
    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, es, cost);
        es++;
    }

    void read(int m = -1, bool weighted = false, bool directed = false, int index = 1) {
        if (m == -1) {
            assert(!g.empty());
            m = int(g.size()) - 1;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a -= index, b -= index;
            T c = T(1);
            if (weighted) cin >> c;
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
    vector<Edge>& operator[](const int& k) { return g[k]; }
};

template <class T>
vector<T> dijkstra(Graph<T>& g, int s = 0) {
    using P = pair<T, int>;
    vector<T> dp(g.size(), numeric_limits<T>::max());
    priority_queue<P, vector<P>, greater<P>> que;
    dp[s] = 0;
    que.push({0, s});
    while (que.size()) {
        auto [d, v] = que.top();
        que.pop();
        if (dp[v] != d) continue;
        for (auto e : g[v]) {
            if (chmin(dp[e.to], d + e.cost)) que.push({dp[e.to], e.to});
        }
    }
    return dp;
}
template <class T, bool U>
vector<int> BFS(Graph<T, U>& g, int s = 0) {  // 01
    vector<int> dp(g.size(), numeric_limits<int>::max());
    deque<int> que;
    dp[s] = 0;
    que.push_front(s);
    while (que.size()) {
        auto v = que.front();
        que.pop_front();
        for (auto e : g[v]) {
            if (chmin(dp[e.to], dp[v] + e.cost)) {
                if (e.cost == 0)
                    que.push_front(e.to);
                else
                    que.push_back(e.to);
            }
        }
    }
    return dp;
}
template <class T>
tuple<int, int, T> Diameter(Graph<T>& g) {
    auto d = dijkstra(g, 0);
    int u = max_element(d.begin(), d.end()) - d.begin();
    d = dijkstra(g, u);
    int v = max_element(d.begin(), d.end()) - d.begin();
    return make_tuple(u, v, d[v]);
}
template <typename G>
vector<int> Path(G& g, int u, int v) {
    vector<int> path;
    vector<bool> vis(g.size());
    bool found = false;
    function<void(int, int)> dfs = [&](int cur, int par) {
        path.push_back(cur);
        vis[cur] = true;
        if (cur == v) {
            found = true;
            return;
        }
        for (int nxt : g[cur]) {
            if (nxt == par) continue;
            if (vis[nxt]) continue;
            dfs(nxt, cur);
            if (found) return;
        }
        if (found) return;
        path.pop_back();
    };
    dfs(u, -1);
    return path;
}
template <class G>
struct HLD {
    G g;
    vector<int> sz, in, out, par, head, dep, ord;
    HLD(G& g, int root = 0)
        : g(g), sz((int)g.size()), in((int)g.size()), out((int)g.size()), par((int)g.size()), head((int)g.size(), root), dep((int)g.size()) {
        dfs_sz(root, -1);
        dfs_hld(root, -1);
    }
    void dfs_sz(int v, int p) {
        par[v] = p;
        sz[v] = 1;
        if (g[v].size() && g[v][0] == p) swap(g[v][0], g[v].back());
        for (auto& i : g[v]) {
            if (i != p) {
                dep[i] = dep[v] + 1;
                dfs_sz(i, v);
                sz[v] += sz[i];
                if (sz[g[v][0]] < sz[i]) swap(g[v][0], i);
            }
        }
    }
    void dfs_hld(int v, int p) {
        in[v] = ord.size();
        ord.push_back(v);
        for (auto i : g[v]) {
            if (i != p) {
                if (int(i) == int(g[v][0])) {
                    // Heavy
                    head[i] = head[v];
                } else {
                    // Light
                    head[i] = i;
                }
                dfs_hld(i, v);
            }
        }
        out[v] = ord.size();
    }
    int lca(int u, int v) {
        while (1) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
    int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
    int la(int v, int d) {
        while (v != -1) {
            int u = head[v];
            if (in[v] - d >= in[u]) return ord[in[v] - d];
            d -= in[v] - in[u] + 1, v = par[u];
        }
        return -1;
    }
    int jump(int from, int to, int d) {
        int l = lca(from, to);
        if (d <= dep[from] - dep[l]) return la(from, d);
        d -= dep[from] - dep[l];
        if (d <= dep[to] - dep[l]) return la(to, dep[to] - dep[l] - d);
        return -1;
    }
};
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
struct UnionFind {
    vector<int> par, siz;
    vector<ll> val;
    UnionFind(int x) {
        par.resize(x);
        siz.resize(x);
        val.resize(x);
        for (int i = 0; i < x; i++) {
            par[i] = i;
            siz[i] = 1;
        }
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        val[x] += val[y];
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return siz[find(x)]; }
};
template <class S, S (*op)(S, S), S (*e)()>
struct dual_segtree {
    int sz = 1, log = 0;
    vector<S> lz;
    dual_segtree() = default;
    dual_segtree(int n) : dual_segtree(vector<S>(n, e())) {}
    dual_segtree(vector<S> a) {
        int n = a.size();
        while (sz < n) {
            sz <<= 1;
            log++;
        }
        lz.assign(sz << 1, e());
        for (int i = 0; i < n; i++) lz[i + sz] = a[i];
    }
    void push(int k) {
        int b = __builtin_ctz(k);
        for (int d = log; d > b; d--) {
            lz[k >> d << 1] = op(lz[k >> d << 1], lz[k >> d]);
            lz[k >> d << 1 | 1] = op(lz[k >> d << 1 | 1], lz[k >> d]);
            lz[k >> d] = e();
        }
    }
    void apply(int l, int r, S x) {
        l += sz, r += sz;
        push(l);
        push(r);
        while (l < r) {
            if (l & 1) {
                lz[l] = op(lz[l], x);
                l++;
            }
            if (r & 1) {
                r--;
                lz[r] = op(lz[r], x);
            }
            l >>= 1, r >>= 1;
        }
    }
    S get(int k) {
        k += sz;
        S res = e();
        while (k) {
            res = op(res, lz[k]);
            k >>= 1;
        }
        return res;
    }
};
template <class T>
struct BIT {
    vector<T> a;
    BIT(int n) : a(n + 1) {}
    void add(int i, T x) {
        i++;
        while (i < (int)a.size()) a[i] += x, i += i & -i;
    }
    //[0,r)
    T sum(int r) {
        T s = 0;
        while (r) s += a[r], r -= r & -r;
        return s;
    }
    T sum(int l, int r) { return sum(r) - sum(l); }
    // minimize i s.t. sum(i) >= w
    int lower_bound(ll w) {
        int x = 0, N = a.size() - 1;
        for (int k = 1 << __lg(N); k; k >>= 1) {
            if (x + k <= N && a[x + k] < w) {
                w -= a[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};
void solve() {}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) solve();
}