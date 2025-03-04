#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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