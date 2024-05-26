#include <atcoder/modint>
#include <iostream>
template <int T>
inline std::ostream &operator<<(std::ostream &os, const atcoder::static_modint<T> &p) {
    return os << p.val();
}
template <int T>
inline std::istream &operator>>(std::istream &is, atcoder::static_modint<T> &a) {
    int64_t t;
    is >> t;
    a = t;
    return is;
}