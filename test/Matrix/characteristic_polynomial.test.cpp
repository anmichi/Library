#include "../../Matrix.cpp"
#include "../../modint.cpp"
#include "../../template.cpp"
int main() {
    int n;
    cin >> n;
    Matrix<modint<998244353>> a(n);
    cin >> a;
    cout << a.characteristic_polynomial() << endl;
}