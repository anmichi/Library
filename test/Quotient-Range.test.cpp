// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/enumerate_quotients
#include "../Quotient-Range.cpp"
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    auto qr = quotient_range<long long>(n);
    assert(qr[0].first.first == 1);
    assert(qr.back().first.second == n);
    for (int i = 0; i < qr.size() - 1; i++) {
        assert(qr[i].first.second + 1 == qr[i + 1].first.first);
    }
    cout << qr.size() << endl;
    reverse(qr.begin(), qr.end());
    for (auto [rng, z] : qr) cout << z << " ";
    cout << endl;
}