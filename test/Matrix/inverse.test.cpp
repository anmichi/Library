#include "../../Matrix.cpp"
#include "../../modint.cpp"
#include "../../template.cpp"
int main() {
    int n;
    cin >> n;
    Matrix<modint<998244353>> a(n);
    cin >> a;
    if (a.determinant() == 0)
        cout << -1 << endl;
    else
        cout << a.inverse() << endl;
}