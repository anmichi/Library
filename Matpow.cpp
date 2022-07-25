#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Matrix {
    int n;
    vector<vector<T>> m;
    Matrix() : Matrix(0) {}
    Matrix(int x) : Matrix(vector<vector<T>>(x, vector<T>(x, 0))) {}
    Matrix(const vector<vector<T>>& a) {
        n = a.size();
        m = a;
    }
    vector<T>& operator[](int i) { return m[i]; }
    const vector<T>& operator[](int i) const { return m[i]; }
    static Matrix identity(int x) {
        Matrix res(x);
        for (int i = 0; i < x; i++) res[i][i] = 1;
        return res;
    }
    Matrix operator+(const Matrix& a) const {
        Matrix x = (*this);
        return x += a;
    }
    Matrix operator*(const Matrix& a) const {
        Matrix x = (*this);
        return x *= a;
    }
    Matrix& operator+=(const Matrix& a) {
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = (m[i][j] + a[i][j]) % mod;
            }
        }
        m = res.m;
        return *this;
    }
    Matrix& operator*=(const Matrix& a) {
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    res[i][j] += m[i][k] * a[k][j];
                    res[i][j] %= mod;
                }
            }
        }
        m = res.m;
        return *this;
    }
    Matrix pow(ll b) const {
        Matrix x = *this, res = identity(n);
        while (b) {
            if (b & 1) {
                res *= x;
            }
            x *= x;
            b >>= 1;
        }
        return res;
    }
};
