// C++ includes used for precompiling -*- C++ -*-
// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.
// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://w...content-available-to-author-only...u.org/licenses/>.
/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */
// 17.4.1.2 Headers
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>

#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
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
template <class T>
inline void compress(vector<T> &a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}
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
constexpr int INF = 1001001001;
constexpr ll llINF = 3000000000000000010;
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
    modint &operator+=(const modint &p) {
        if ((x += p.x) >= modulo) x -= modulo;
        return *this;
    }
    modint &operator-=(const modint &p) {
        if ((x += modulo - p.x) >= modulo) x -= modulo;
        return *this;
    }
    modint &operator*=(const modint &p) {
        x = (int)(1LL * x * p.x % modulo);
        return *this;
    }
    modint &operator/=(const modint &p) {
        *this *= p.inv();
        return *this;
    }
    modint operator-() const { return modint(-x); }
    modint operator+(const modint &p) const { return modint(*this) += p; }
    modint operator-(const modint &p) const { return modint(*this) -= p; }
    modint operator*(const modint &p) const { return modint(*this) *= p; }
    modint operator/(const modint &p) const { return modint(*this) /= p; }
    bool operator==(const modint &p) const { return x == p.x; }
    bool operator!=(const modint &p) const { return x != p.x; }
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
    friend ostream &operator<<(ostream &os, const modint &p) { return os << p.x; }
    friend istream &operator>>(istream &is, modint &a) {
        int64_t t;
        is >> t;
        a = modint<modulo>(t);
        return (is);
    }
    int val() const { return x; }
    static constexpr int mod() { return modulo; }
    static constexpr int half() { return (modulo + 1) >> 1; }
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
template <class T>
struct Matrix {
    vector<vector<T>> m;
    Matrix() = default;
    Matrix(int x) : m(vector(x, vector<T>(x, 0))) {}
    Matrix(const vector<vector<T>> &a) : m(a) {}
    vector<T> &operator[](int i) { return m[i]; }
    const vector<T> &operator[](int i) const { return m[i]; }
    static Matrix identity(int x) {
        Matrix res(x);
        for (int i = 0; i < x; i++) res[i][i] = 1;
        return res;
    }
    static Matrix zero(int x) { return Matrix(x); }

    Matrix operator+() const { return (*this); }
    Matrix operator-() const { return Matrix(this->m.size()) - (*this); }
    Matrix operator+(const Matrix &a) const {
        Matrix x = (*this);
        return x += a;
    }
    Matrix operator-(const Matrix &a) const {
        Matrix x = (*this);
        return x -= a;
    }
    Matrix operator*(const Matrix &a) const {
        Matrix x = (*this);
        return x *= a;
    }
    Matrix operator*(const T &a) const {
        Matrix x = (*this);
        return x *= a;
    }
    Matrix &operator+=(const Matrix &a) {
        int n = m.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] += a[i][j];
            }
        }
        return *this;
    }
    Matrix &operator-=(const Matrix &a) {
        int n = m.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] -= a[i][j];
            }
        }
        return *this;
    }
    Matrix &operator*=(const Matrix &a) {
        int n = m.size();
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] += m[i][k] * a[k][j];
                }
            }
        }
        m = res.m;
        return *this;
    }
    Matrix &operator*=(const T &a) {
        int n = m.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] *= a;
            }
        }
        return *this;
    }
    Matrix pow(ll b) const {
        Matrix x = *this, res = identity(x.m.size());
        while (b) {
            if (b & 1) {
                res *= x;
            }
            x *= x;
            b >>= 1;
        }
        return res;
    }
    T determinant() {
        int n = m.size();
        Matrix A(*this);
        T ret = 1;
        for (int i = 0; i < n; i++) {
            int pivot = -1;
            for (int j = i; j < n; j++) {
                if (A[j][i] != 0) pivot = j;
            }
            if (pivot == -1) return T(0);
            if (i != pivot) {
                ret *= -1;
                swap(A[i], A[pivot]);
            }
            ret *= A[i][i];
            T tmp = T(1) / A[i][i];
            for (int j = 0; j < n; j++) {
                A[i][j] *= tmp;
            }
            for (int j = i + 1; j < n; j++) {
                T a = A[j][i];
                for (int k = 0; k < n; k++) {
                    A[j][k] -= A[i][k] * a;
                }
            }
        }
        return ret;
    }
    Matrix inverse() {
        assert(determinant() != 0);
        int n = m.size();
        Matrix ret = identity(n);
        Matrix A(*this);
        for (int i = 0; i < n; i++) {
            int pivot = -1;
            for (int j = i; j < n; j++) {
                if (A[j][i] != 0) pivot = j;
            }
            if (i != pivot) {
                swap(ret[i], ret[pivot]);
                swap(A[i], A[pivot]);
            }
            T tmp = T(1) / A[i][i];
            for (int j = 0; j < n; j++) {
                A[i][j] *= tmp;
                ret[i][j] *= tmp;
            }
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                T a = A[j][i];
                for (int k = 0; k < n; k++) {
                    A[j][k] -= A[i][k] * a;
                    ret[j][k] -= ret[i][k] * a;
                }
            }
        }
        return ret;
    }
    vector<T> characteristic_polynomial() {
        int n = m.size();
        if (n == 0) return {1};
        Matrix A(*this);
        for (int i = 1; i < n; i++) {
            int pivot = -1;
            for (int j = i; j < n; j++) {
                if (A[j][i - 1] != 0) pivot = j;
            }
            if (pivot == -1) continue;
            if (i != pivot) {
                swap(A[i], A[pivot]);
                for (int j = 0; j < n; j++) swap(A[j][i], A[j][pivot]);
            }
            T tmp = T(1) / A[i][i - 1];
            vector<T> c(n);
            for (int j = i + 1; j < n; j++) c[j] = tmp * A[j][i - 1];
            for (int j = i + 1; j < n; j++) {
                for (int k = i - 1; k < n; k++) {
                    A[j][k] -= A[i][k] * c[j];
                }
            }
            for (int j = 0; j < n; j++) {
                for (int k = i + 1; k < n; k++) {
                    A[j][i] += A[j][k] * c[k];
                }
            }
        }
        vector dp(n + 1, vector<T>(n + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i + 1][j] -= dp[i][j] * A[i][i];
                dp[i + 1][j + 1] += dp[i][j];
            }
            T p = 1;
            for (int k = i + 1; k < n; k++) {
                p *= A[k][k - 1];
                for (int j = 0; j <= i; j++) dp[k + 1][j] -= dp[i][j] * p * A[i][k];
            }
        }
        return dp[n];
    }
    friend ostream &operator<<(ostream &os, const Matrix &a) {
        int n = a.m.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                os << a[i][j];
                if (j != n - 1) os << " ";
            }
            os << "\n";
        }
        return os;
    }
    friend istream &operator>>(istream &is, Matrix &a) {
        int n = a.m.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                is >> a[i][j];
            }
        }
        return is;
    }
};

template <class T, T (*op)(T, T), T (*e)()>
struct disjointsparsetable {
    vector<vector<T>> table;
    vector<int> logtable;
    disjointsparsetable() = default;
    disjointsparsetable(vector<T> v) {
        int len = 0;
        while ((1 << len) <= v.size()) len++;
        table.assign(len, vector<T>(1 << len, e()));
        for (int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];
        for (int i = 1; i < len; i++) {
            int shift = 1 << i;
            for (int j = 0; j < (int)v.size(); j += shift << 1) {
                int t = min(j + shift, (int)v.size());
                table[i][t - 1] = v[t - 1];
                for (int k = t - 2; k >= j; k--) table[i][k] = op(v[k], table[i][k + 1]);
                if (v.size() <= t) break;
                table[i][t] = v[t];
                int r = min(t + shift, (int)v.size());
                for (int k = t + 1; k < r; k++) table[i][k] = op(table[i][k - 1], v[k]);
            }
        }
        logtable.resize(1 << len);
        for (int i = 2; i < logtable.size(); i++) {
            logtable[i] = logtable[(i >> 1)] + 1;
        }
    }
    T query(int l, int r) {
        if (l == r) return e();
        if (l >= --r) return table[0][l];
        int len = logtable[l ^ r];
        return op(table[len][l], table[len][r]);
    };
};
pair<int, int> lcatree_op(pair<int, int> a, pair<int, int> b) { return min(a, b); }
pair<int, int> lcatree_e() { return {1000000000, -1}; }
struct lca_tree {
    int n, size;
    vector<int> in, ord, depth;
    disjointsparsetable<pair<int, int>, lcatree_op, lcatree_e> st;
    lca_tree(vector<vector<int>> g, int root = 0) : n((int)g.size()), size(log2(n) + 2), in(n), depth(n, n) {
        depth[root] = 0;
        function<void(int, int)> dfs = [&](int v, int p) {
            in[v] = (int)ord.size();
            ord.push_back(v);
            for (int u : g[v]) {
                if (u == p) continue;
                if (depth[u] > depth[v] + 1) {
                    depth[u] = depth[v] + 1;
                    dfs(u, v);
                    ord.push_back(v);
                }
            }
        };
        dfs(root, -1);
        vector<pair<int, int>> vec((int)ord.size());
        for (int i = 0; i < (int)ord.size(); i++) {
            vec[i] = make_pair(depth[ord[i]], ord[i]);
        }
        st = vec;
    }
    int lca(int u, int v) {
        if (in[u] > in[v]) swap(u, v);
        if (u == v) return u;
        return st.query(in[u], in[v]).second;
    }
    int dist(int u, int v) {
        int l = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[l];
    }
};
struct auxiliary_tree : lca_tree {
    vector<vector<int>> G;
    auxiliary_tree(vector<vector<int>> &g) : lca_tree(g), G(n) {}
    pair<int, vector<int>> query(vector<int> vs, bool decending = false) {
        assert(!vs.empty());
        sort(vs.begin(), vs.end(), [&](int a, int b) { return in[a] < in[b]; });
        int m = vs.size();
        stack<int> st;
        st.push(vs[0]);
        for (int i = 0; i < m - 1; i++) {
            int w = lca(vs[i], vs[i + 1]);
            if (w != vs[i]) {
                int l = st.top();
                st.pop();
                while (!st.empty() && depth[w] < depth[st.top()]) {
                    if (!decending) G[l].push_back(st.top());
                    G[st.top()].push_back(l);
                    l = st.top();
                    st.pop();
                }
                if (st.empty() || st.top() != w) {
                    st.push(w);
                    vs.push_back(w);
                }
                if (!decending) G[l].push_back(w);
                G[w].push_back(l);
            }
            st.push(vs[i + 1]);
        }
        while (st.size() > 1) {
            int x = st.top();
            st.pop();
            if (!decending) G[x].push_back(st.top());
            G[st.top()].push_back(x);
        }
        // {root,vertex_list}
        return make_pair(st.top(), vs);
    }
    void clear(vector<int> vs) {
        for (int v : vs) G[v].clear();
    }
};
template <class T>
vector<T> dijkstra(vector<vector<pair<int, T>>> &g, vector<int> start) {
    using P = pair<T, int>;
    vector<T> dp(g.size(), numeric_limits<T>::max());
    priority_queue<P, vector<P>, greater<P>> que;
    for (int s : start) {
        dp[s] = 0;
        que.push({0, s});
    }
    while (que.size()) {
        auto [d, v] = que.top();
        que.pop();
        if (dp[v] != d) continue;
        for (auto [u, c] : g[v]) {
            if (chmin(dp[u], d + c)) que.push({dp[u], u});
        }
    }
    return dp;
}

vector<int> BFS01(vector<vector<pair<int, int>>> &g, vector<int> start) {
    vector<int> dp(g.size(), numeric_limits<int>::max());
    deque<int> que;
    for (int s : start) {
        dp[s] = 0;
        que.push_front(s);
    }
    while (que.size()) {
        auto v = que.front();
        que.pop_front();
        for (auto [u, c] : g[v]) {
            if (chmin(dp[u], dp[v] + c)) {
                if (c == 0)
                    que.push_front(u);
                else
                    que.push_back(u);
            }
        }
    }
    return dp;
}
struct Mo {
    int n;
    vector<pair<int, int>> lr;

    explicit Mo(int n) : n(n) {}

    void add(int l, int r) { /* [x, y) */ lr.emplace_back(l, r); }

    template <typename AL, typename AR, typename EL, typename ER, typename O>
    void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
        int q = (int)lr.size();
        int bs = max<int>(1, 1.0 * n / max<double>(1.0, sqrt(q * 2.0 / 3.0)));
        vector<int> ord(q);
        iota(begin(ord), end(ord), 0);
        sort(begin(ord), end(ord), [&](int a, int b) {
            int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
            if (ablock != bblock) return ablock < bblock;
            return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
        });
        int l = 0, r = 0;
        for (auto idx : ord) {
            while (l > lr[idx].first) add_left(--l);
            while (r < lr[idx].second) add_right(r++);
            while (l < lr[idx].first) erase_left(l++);
            while (r > lr[idx].second) erase_right(--r);
            out(idx);
        }
    }

    template <typename A, typename E, typename O>
    void build(const A &add, const E &erase, const O &out) {
        build(add, add, erase, erase, out);
    }
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

struct LowLink {
    vector<vector<int>> g;
    vector<int> ord, low, out;
    vector<bool> used;
    vector<pair<int, int>> bridge;
    vector<pair<int, int>> articulation;
    int unions;
    LowLink(vector<vector<int>> g) : g(g) {
        int n = (int)g.size();
        ord.resize(n);
        low.resize(n);
        out.resize(n);
        used.resize(n);
        unions = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i, t, -1);
                unions++;
            }
        }
    }
    void dfs(int v, int &t, int par) {
        used[v] = true;
        ord[v] = t++, low[v] = ord[v];
        int cnt = 0;
        bool par_back = false;
        for (int to : g[v]) {
            if (!used[to]) {
                dfs(to, t, v);
                low[v] = min(low[v], low[to]);
                if (ord[v] < low[to]) bridge.push_back(minmax(v, to));
                if (ord[v] <= low[to]) cnt++;
            } else if (to != par || par_back) {
                low[v] = min(low[v], ord[to]);
            } else
                par_back = true;
        }
        if (par != -1) cnt++;
        if (cnt >= 2) articulation.push_back({v, cnt});
        out[v] = t;
    }
};
namespace Geometry {

constexpr double eps = 1e-10;
template <class T>
constexpr int sign(const T &a) {
    if (isZero(a)) return 0;
    if (a > 0) return 1;
    return -1;
}
template <class T, class U>
constexpr bool equal(const T &a, const U &b) {
    return isZero(a - b);
}
template <class T>
constexpr bool isZero(const T &a) {
    if (is_floating_point<T>()) return fabs(a) < eps;
    return a == 0;
}
template <class T>
constexpr T square(const T &a) {
    return a * a;
}
template <class T>
struct Vec2 {
    T x, y;
    Vec2() = default;
    Vec2(T x, T y) : x(x), y(y) {};
    constexpr Vec2 &operator+=(const Vec2 &P) {
        x += P.x, y += P.y;
        return *this;
    }
    constexpr Vec2 &operator-=(const Vec2 &P) {
        x -= P.x, y -= P.y;
        return *this;
    }
    constexpr Vec2 &operator*=(const T k) {
        x *= k, y *= k;
        return *this;
    }
    constexpr Vec2 &operator/=(const T k) {
        x /= k, y /= k;
        return *this;
    }
    constexpr Vec2 operator+() const { return *this; }
    constexpr Vec2 operator-() const { return {-x, -y}; }
    constexpr Vec2 operator+(const Vec2 &P) const { return {x + P.x, y + P.y}; }
    constexpr Vec2 operator-(const Vec2 &P) const { return {x - P.x, y - P.y}; }
    constexpr Vec2 operator*(const T k) const { return {x * k, y * k}; }
    constexpr Vec2 operator/(const T k) const { return {x / k, y / k}; }
    constexpr bool operator==(const Vec2 &P) const { return isZero(x - P.x) && isZero(y - P.y); }
    constexpr bool operator!=(const Vec2 &P) const { return !(*this == P); }
    constexpr bool operator<(const Vec2 &P) const {
        if (!isZero(x - P.x)) return x < P.x;
        return y < P.y;
    }
    constexpr bool operator>(const Vec2 &P) const { return P < *this; }
    constexpr bool isZeroVec() const { return x == T(0) && y == T(0); }
    constexpr T abs2() const { return x * x + y * y; }
    constexpr T abs() const { return sqrt(abs2()); }
    constexpr T dot(const Vec2 &v) const { return x * v.x + y * v.y; }
    constexpr T cross(const Vec2 &v) const { return x * v.y - y * v.x; }
    constexpr T dist(const Vec2 &P) const { return (P - (*this)).abs(); }
    constexpr T distSq(const Vec2 &P) const { return (P - (*this)).abs2(); }
    constexpr T unitVec() const { return (*this) / abs(); }
    Vec2 &unitize() { return *this /= abs(); }
    friend constexpr T abs2(const Vec2 &P) { return P.abs2(); }
    friend constexpr T abs(const Vec2 &P) { return P.abs(); }
    friend constexpr T dot(const Vec2 &P, const Vec2 &Q) { return P.dot(Q); }
    friend constexpr T dot(const Vec2 &A, const Vec2 &B, const Vec2 &C) { return (B - A).dot(C - A); }
    friend constexpr T cross(const Vec2 &P, const Vec2 &Q) { return P.cross(Q); }
    friend constexpr T cross(const Vec2 &A, const Vec2 &B, const Vec2 &C) { return (B - A).cross(C - A); }
    friend constexpr T dist(const Vec2 &P, const Vec2 &Q) { return P.dist(Q); }
    friend constexpr T distSq(const Vec2 &P, const Vec2 &Q) { return P.distSq(Q); }
};
template <class T>
constexpr int ccw(const Vec2<T> &A, const Vec2<T> &B, const Vec2<T> &C) {
    if (cross(B - A, C - A) > eps) return +1;
    if (cross(B - A, C - A) < -eps) return -1;
    if (dot(B - A, C - A) < -eps) return +2;
    if (abs2(B - A) + eps < abs2(C - A)) return -2;
    return 0;
}
struct Line {
    using T = double;
    using Point = Vec2<T>;
    Point A, B;
    Line() = default;
    Line(Point A, Point B) : A(A), B(B) {}
    constexpr Point vec() const { return B - A; }
    constexpr bool isParallelTo(const Line &L) const { return isZero(cross(vec(), L.vec())); }
    constexpr bool isOrthogonalTo(const Line &L) const { return isZero(dot(vec(), L.vec())); }
    constexpr T distanceFrom(const Point &P) const { return abs(cross(P - A, vec())) / vec().abs(); }
    constexpr Point crosspoint(const Line &L) const { return A + vec() * (cross(A - L.A, L.vec())) / cross(L.vec(), vec()); }
    friend constexpr Point crosspoint(const Line &L, const Line &M) { return L.crosspoint(M); }
};
struct Segment : Line {
    Segment() = default;
    Segment(Point A, Point B) : Line(A, B) {}
    constexpr bool intersect(const Segment &L) const { return ccw(L.A, L.B, A) * ccw(L.A, L.B, B) <= 0 && ccw(A, B, L.A) * ccw(A, B, L.B) <= 0; }
    constexpr T distanceFrom(const Point &P) const {
        if (dot(P - A, vec()) < 0) return P.dist(A);
        if (dot(P - B, vec()) > 0) return P.dist(B);
        return Line::distanceFrom(P);
    }
    constexpr T distanceFrom(const Segment &L) const {
        if (intersect(L)) return 0;
        return min({Segment::distanceFrom(L.A), Segment::distanceFrom(L.B), Segment(L).distanceFrom(A), Segment(L).distanceFrom(B)});
    }
};
struct intLine {
    using T = long long;
    using Point = Vec2<T>;
    Point A, B;
    intLine() = default;
    intLine(Point A, Point B) : A(A), B(B) {}
    constexpr Point vec() const { return B - A; }
    constexpr bool isParallelTo(const intLine &L) const { return isZero(cross(vec(), L.vec())); }
    constexpr bool isOrthogonalTo(const intLine &L) const { return isZero(dot(vec(), L.vec())); }
    constexpr T distanceSqFrom(const Point &P) const { return square(cross(P - A, vec())) / vec().abs2(); }
    // constexpr Point crosspoint(const intLine &L) const { return A + vec() * (cross(A - L.A, L.vec())) / cross(L.vec(), vec()); }
};
struct intSegment : intLine {
    intSegment() = default;
    intSegment(Point A, Point B) : intLine(A, B) {}
    constexpr bool intersect(const intSegment &L) const { return ccw(L.A, L.B, A) * ccw(L.A, L.B, B) <= 0 && ccw(A, B, L.A) * ccw(A, B, L.B) <= 0; }
    constexpr T distanceSqFrom(const Point &P) {
        if (dot(P - A, vec()) < 0) return P.distSq(A);
        if (dot(P - B, vec()) > 0) return P.distSq(B);
        return intLine::distanceSqFrom(P);
    }
    constexpr T distanceSqFrom(const intSegment &L) {
        if (intersect(L)) return 0;
        return min(
            {intSegment::distanceSqFrom(L.A), intSegment::distanceSqFrom(L.B), intSegment(L).distanceSqFrom(A), intSegment(L).distanceSqFrom(B)});
    }
    friend constexpr bool intersect(const intSegment &L, const intSegment &M) { return L.intersect(M); }
};
template <class T>
vector<T> convex_hull(vector<T> ps) {
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    int n = ps.size();
    if (n <= 2) return ps;
    vector<T> qs;
    for (auto &p : ps) {
        //<=0 if want to remove "3 points on a same line"
        while (qs.size() > 1 && cross(qs[qs.size() - 2], qs[qs.size() - 1], p) <= 0) {
            qs.pop_back();
        }
        qs.push_back(p);
    }
    int t = qs.size();
    for (int i = n - 2; i >= 0; i--) {
        T &p = ps[i];
        while ((int)qs.size() > t && cross(qs[qs.size() - 2], qs[qs.size() - 1], p) <= 0) {
            qs.pop_back();
        }
        if (i) qs.push_back(p);
    }
    return qs;
}

template <typename T>
inline istream &operator>>(istream &is, Vec2<T> &rhs) {
    return is >> rhs.x >> rhs.y;
}
template <typename T>
inline ostream &operator<<(ostream &os, Vec2<T> &rhs) {
    return os << rhs.x << " " << rhs.y;
}
inline istream &operator>>(istream &is, Line &rhs) { return is >> rhs.A >> rhs.B; }
inline ostream &operator<<(ostream &os, Line &rhs) { return os << rhs.A << rhs.B; }
inline istream &operator>>(istream &is, Segment &rhs) { return is >> rhs.A >> rhs.B; }
inline ostream &operator<<(ostream &os, Segment &rhs) { return os << rhs.A << rhs.B; }
inline istream &operator>>(istream &is, intLine &rhs) { return is >> rhs.A >> rhs.B; }
inline ostream &operator<<(ostream &os, intLine &rhs) { return os << rhs.A << rhs.B; }
inline istream &operator>>(istream &is, intSegment &rhs) { return is >> rhs.A >> rhs.B; }
inline ostream &operator<<(ostream &os, intSegment &rhs) { return os << rhs.A << rhs.B; }
};  // namespace Geometry
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}
struct HLD {
    vector<vector<int>> g;
    vector<int> sz, in, out, par, head, dep, ord;
    HLD(vector<vector<int>> &g_, int root = 0)
        : g(g_), sz((int)g_.size()), in((int)g_.size()), out((int)g_.size()), par((int)g_.size()), head((int)g_.size(), root), dep((int)g_.size()) {
        dfs_sz(root, -1);
        dfs_hld(root, -1);
    }
    void dfs_sz(int v, int p) {
        par[v] = p;
        sz[v] = 1;
        if (g[v].size() && g[v][0] == p) swap(g[v][0], g[v].back());
        for (auto &i : g[v]) {
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
                if (i == g[v][0]) {
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
inline istream &operator>>(istream &is, pair<T, U> &rhs) {
    return is >> rhs.first >> rhs.second;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
    for (auto &e : v) is >> e;
    return is;
}
template <typename T, typename U>
inline ostream &operator<<(ostream &os, const pair<T, U> &rhs) {
    return os << rhs.first << " " << rhs.second;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto itr = v.begin(), end_itr = v.end(); itr != end_itr;) {
        os << *itr;
        if (++itr != end_itr) os << " ";
    }
    return os;
}

struct FunctionMo {
    int n;
    vector<pair<int, int>> xy;

    explicit FunctionMo(int n) : n(n) {}

    void add(int x, int y) { xy.emplace_back(x, y); }

    template <typename AX, typename SX, typename AY, typename SY, typename O>
    void build(const AX &add_x, const SX &sub_x, const AY &add_y, const SY &sub_y, const O &out) {
        int q = (int)xy.size();
        int bs = max<int>(1, sqrt(n));
        vector<int> ord(q);
        iota(begin(ord), end(ord), 0);
        sort(begin(ord), end(ord), [&](int a, int b) {
            int ablock = xy[a].first / bs, bblock = xy[b].first / bs;
            if (ablock != bblock) return ablock < bblock;
            return (ablock & 1) ? xy[a].second > xy[b].second : xy[a].second < xy[b].second;
        });
        int x = 0, y = 0;
        for (auto idx : ord) {
            while (x > xy[idx].first) add_x(x++, y);
            while (y < xy[idx].second) add_y(x, y++);
            while (x < xy[idx].first) sub_x(x--, y);
            while (y > xy[idx].second) sub_y(x, y--);
            out(idx);
        }
    }

    template <typename A, typename E, typename O>
    void build(const A &add, const E &erase, const O &out) {
        build(add, add, erase, erase, out);
    }
};
struct UnionFind {
    vector<int> par, siz;
    UnionFind(int x) {
        par.resize(x);
        siz.resize(x);
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

        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return siz[find(x)]; }
};
template <class T>
struct BIT {
    // 1-indexed
    int n, beki = 1;
    vector<T> bit;
    BIT(int x) {
        bit.resize(x + 1, 0);
        n = x;
        while (beki * 2 <= n) beki *= 2;
    }
    T sum(int i) {
        T res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
    T sum(int l, int r) {
        //[l,r]
        return sum(r) - (l == 0 ? 0 : sum(l - 1));
    }
    void add(int i, T x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
    int lowerbound(T w) {
        if (w <= 0) return 0;
        int x = 0;
        for (int k = beki; k > 0; k >>= 1) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};
template <typename T, typename Compare = less<T>>
vector<pair<int, T>> monotone_minima(int H, int W, const function<T(int, int)> &f, const Compare &comp = Compare()) {
    vector<pair<int, T>> dp(H);
    function<void(int, int, int, int)> dfs = [&](int top, int bottom, int left, int right) {
        if (top > bottom) return;
        int line = (top + bottom) / 2;
        T ma;
        int mi = -1;
        for (int i = left; i <= right; i++) {
            T cst = f(line, i);
            if (mi == -1 || comp(cst, ma)) {
                ma = cst;
                mi = i;
            }
        }
        dp[line] = make_pair(mi, ma);
        dfs(top, line - 1, left, mi);
        dfs(line + 1, bottom, mi, right);
    };
    dfs(0, H - 1, 0, W - 1);
    return dp;
}
using mint = modint<998244353>;
void solve() {
    int n;
    cin >> n;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t) solve();
}