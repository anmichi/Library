#include "../../Matrix.cpp"
#include "../../modint.cpp"
#include "../../template.cpp"
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    long long k;
    cin >> n >> k;
    Matrix<modint<998244353>> a(n);
    cin >> a;
    cout << a.pow(k) << endl;
}