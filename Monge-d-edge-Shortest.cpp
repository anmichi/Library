#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
constexpr int64_t llINF = 3000000000000000000;
constexpr int INF = 1000000000;
template <class T, typename Compare = less<T>>
vector<pair<int, T>> monotone_minima(int Top, int Bottom, int Left, int Right, const function<T(int, int)> &f, const Compare &comp = Compare()) {
    vector<pair<int, T>> res(Bottom - Top);
    function<void(int, int, int, int)> dfs = [&](int top, int bottom, int left, int right) {
        if (top >= bottom) return;
        int line = (top + bottom) / 2;
        T ma;
        int mi = -1;
        for (int i = left; i < right; i++) {
            T cst = f(line, i);
            if (mi == -1 || comp(cst, ma)) {
                ma = cst;
                mi = i;
            }
        }
        res[line - Top] = make_pair(mi, ma);
        dfs(top, line, left, mi + 1);
        dfs(line + 1, bottom, mi, right);
    };
    dfs(Top, Bottom, Left, Right);
    return res;
}
void solve() {
    int n, d;
    cin >> n >> d;
    vector<ll> p(n + 1), c(n + 1), x;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        c[i] = c[i - 1] + p[i];
        rep(j, p[i]) x.push_back(i);
    }
    auto st_cnt = p;
    for (int i = 1; i <= n; i++) p[i] *= i;
    auto st_sum = p;
    for (int i = 1; i <= n; i++) {
        st_cnt[i] += st_cnt[i - 1];
        st_sum[i] += st_sum[i - 1];
    }
    auto h = [&](ll k) {
        vector<pair<ll, int>> dp(n + 1, make_pair(llINF, INF));
        dp[0] = {0, 0};
        auto f = [&](int i, int j) {
            // j->i
            if (i <= j) return make_pair((ll)llINF, INF);
            int val = x[(c[j] + c[i] - 1) / 2];
            ll cost = k;
            cost += (st_sum[i] - st_sum[val]) - val * (st_cnt[i] - st_cnt[val]);
            cost -= (st_sum[val - 1] - st_sum[j]) - val * (st_cnt[val - 1] - st_cnt[j]);
            return make_pair(dp[j].first + cost, dp[j].second - 1);
        };
        function<void(int, int)> calc = [&](int l, int r) {
            if (l + 1 == r) return;
            int m = (l + r) / 2;
            calc(l, m);
            //[l,m) -> [m,r)
            auto res = monotone_minima<pair<ll, int>>(m, r, l, m, f);
            for (int i = m; i < r; i++) dp[i] = min(dp[i], res[i - m].second);
            calc(m, r);
            return;
        };
        calc(0, n + 1);
        dp[n].second = -dp[n].second;
        return dp[n];
    };
    const ll BOUND = 10000000000;
    ll left = -BOUND, right = BOUND;
    while (right - left > 1) {
        ll k = left + (right - left) / 2;
        auto [gmax, argmax] = h(k);
        if (argmax > d)
            left = k;
        else
            right = k;
    }
    auto [gmax, argmax] = h(left);
    cout << (ll)(gmax - left * d) << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}