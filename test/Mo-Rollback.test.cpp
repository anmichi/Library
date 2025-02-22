// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_range_mode_query
#include "../Mo-Rollback.cpp"
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (int i = 0; i < n; i++)
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    auto xx = a;
    sort(all(xx));
    xx.erase(unique(all(xx)), xx.end());
    rep(i, n) a[i] = lower_bound(all(xx), a[i]) - xx.begin();
    MoRollback mo(n);
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        mo.add(l, r);
    }
    using P = pair<int, int>;
    P res{0, -1};
    vector<int> cnt(xx.size());
    vector<pair<P, P>> history;
    auto add = [&](int i) {
        history.push_back({res, {a[i], cnt[a[i]]}});
        cnt[a[i]]++;
        res = max(res, P{cnt[a[i]], a[i]});
    };
    auto snapshot = [&]() { history.clear(); };
    auto rollback = [&]() {
        while (history.size()) {
            res = history.back().first;
            cnt[history.back().second.first] = history.back().second.second;
            history.pop_back();
        }
    };
    auto clear = [&]() {
        res = {0, -1};
        cnt.assign(xx.size(), 0);
        history.clear();
    };
    vector<P> ans(q);
    auto answer = [&](int i) { ans[i] = res; };
    mo.build(add, snapshot, rollback, clear, answer);
    rep(i, q) cout << xx[ans[i].second] << " " << ans[i].first << "\n";
}