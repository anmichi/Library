#pragma once
#include "SuccinctIndexableDictionary.hpp"
// https://ei1333.github.io/library/structure/wavelet/wavelet-matrix.hpp
template <typename T, int MAXLOG, typename D>
struct WaveletMatrixRectSum {
    size_t length;
    SuccinctIndexableDictionary matrix[MAXLOG];
    vector<D> xs[MAXLOG];
    int mid[MAXLOG];

    WaveletMatrixRectSum() = default;

    WaveletMatrixRectSum(vector<T> y, vector<D> w) : length(y.size()) {
        assert(y.size() == w.size());
        vector<pair<T, T>> v(length);
        for (int i = 0; i < length; i++) v[i] = {y[i], w[i]};
        vector<pair<T, T>> l(length), r(length);
        for (int level = MAXLOG - 1; level >= 0; level--) {
            matrix[level] = SuccinctIndexableDictionary(length + 1);
            int left = 0, right = 0;
            for (int i = 0; i < length; i++) {
                if (((v[i].first >> level) & 1)) {
                    matrix[level].set(i);
                    r[right++] = v[i];
                } else {
                    l[left++] = v[i];
                }
            }
            mid[level] = left;
            matrix[level].build();
            v.swap(l);
            for (int i = 0; i < right; i++) {
                v[left + i] = r[i];
            }
            xs[level].resize(length + 1);
            xs[level][0] = 0;
            for (int i = 0; i < length; i++) xs[level][i + 1] = xs[level][i] + v[i].second;
        }
    }

    pair<int, int> succ(bool f, int l, int r, int level) {
        return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f, r) + mid[level] * f};
    }
    // sum v[i] s.t. (l <= i < r) && (v[i] < upper)
    D rect_sum(int l, int r, T upper) {
        D ret = 0;
        for (int level = MAXLOG - 1; level >= 0; level--) {
            bool f = ((upper >> level) & 1);
            if (f) ret += xs[level][matrix[level].rank(false, r)] - xs[level][matrix[level].rank(false, l)];
            tie(l, r) = succ(f, l, r, level);
        }
        return ret;
    }

    // sum v[i] s.t. (l <= i < r) && (lower <= v[i] < upper)
    D rect_sum(int l, int r, T lower, T upper) { return rect_sum(l, r, upper) - rect_sum(l, r, lower); }
};

template <typename T, int MAXLOG, typename D>
struct CompressedWaveletMatrixRectSum {
    WaveletMatrixRectSum<int, MAXLOG, D> mat;
    vector<T> ys;

    CompressedWaveletMatrixRectSum(vector<T> y, vector<D> w) : ys(y) {
        sort(begin(ys), end(ys));
        ys.erase(unique(begin(ys), end(ys)), end(ys));
        vector<int> t(y.size());
        for (int i = 0; i < y.size(); i++) t[i] = get(y[i]);
        mat = WaveletMatrixRectSum<int, MAXLOG, D>(t, w);
    }

    inline int get(const T& x) { return lower_bound(begin(ys), end(ys), x) - begin(ys); }

    D rect_sum(int l, int r, T upper) { return mat.rect_sum(l, r, get(upper)); }

    D rect_sum(int l, int r, T lower, T upper) { return mat.rect_sum(l, r, get(lower), get(upper)); }
};