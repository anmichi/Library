#include <bits/stdc++.h>
using namespace std;
template <class T>
void multiple_fzt(vector<T>& a) {
    int n = a.size();
    vector<bool> sieve(n, true);
    for (int p = 2; p < n; p++) {
        if (sieve[p]) {
            for (int k = (n - 1) / p; k >= 1; k--) {
                sieve[k * p] = false;
                a[k] += a[k * p];
            }
        }
    }
}
template <class T>
void multiple_fmt(vector<T>& a) {
    int n = a.size();
    vector<bool> sieve(n, true);
    for (int p = 2; p < n; p++) {
        if (sieve[p]) {
            for (int k = 1; k * p < n; k++) {
                sieve[k * p] = false;
                a[k] -= a[k * p];
            }
        }
    }
}
template <class T>
vector<T> gcd_convolution(vector<T> a, vector<T> b) {
    multiple_fzt(a);
    multiple_fzt(b);
    for (int i = 1; i < (int)a.size(); i++) a[i] *= b[i];
    multiple_fmt(a);
    return a;
}

template <class T>
void divisor_fzt(vector<T>& a) {
    int n = a.size();
    vector<bool> sieve(n, true);
    for (int p = 2; p < n; p++) {
        if (sieve[p]) {
            for (int k = 1; k * p < n; k++) {
                sieve[k * p] = false;
                a[k * p] += a[k];
            }
        }
    }
}
template <class T>
void divisor_fmt(vector<T>& a) {
    int n = a.size();
    vector<bool> sieve(n, true);
    for (int p = 2; p < n; p++) {
        if (sieve[p]) {
            for (int k = (n - 1) / p; k >= 1; k--) {
                sieve[k * p] = false;
                a[k * p] -= a[k];
            }
        }
    }
}
template <class T>
vector<T> lcm_convolution(vector<T> a, vector<T> b) {
    divisor_fzt(a);
    divisor_fzt(b);
    for (int i = 1; i < (int)a.size(); i++) a[i] *= b[i];
    divisor_fmt(a);
    return a;
}