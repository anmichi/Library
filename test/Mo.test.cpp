#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"
#include "../Mo.cpp"
int cnt[500010];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    auto xx = a;
    sort(xx.begin(), xx.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());
    for (int i = 0; i < n; i++) a[i] = lower_bound(xx.begin(), xx.end(), a[i]) - xx.begin();
    int ans = 0;
    vector<int> out(q);
    auto add = [&](int i) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 1) ans++;
    };
    auto erase = [&](int i) {
        if (cnt[a[i]] == 1) ans--;
        cnt[a[i]]--;
    };
    auto answer = [&](int i) { out[i] = ans; };
    Mo mo(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        mo.add(l, r);
    }
    mo.build(add, erase, answer);
    for (int i = 0; i < q; i++) cout << out[i] << "\n";
}