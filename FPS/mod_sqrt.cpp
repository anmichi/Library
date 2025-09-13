#include "../template.cpp"
int64_t mod_sqrt(const int64_t& a, const int64_t& p) {
    assert(0 <= a && a < p);
    if (a < 2) return a;
    if (modpow(a, (p - 1) >> 1, p) != 1) return -1;
    int64_t q = p - 1, m = 0;
    while (!(q & 1)) {
        q >>= 1;
        m++;
    }
    int64_t z = 1;
    while (modpow(z, (p - 1) >> 1, p) == 1) z++;
    int64_t c = modpow(z, q, p);
    int64_t t = modpow(a, q, p);
    int64_t r = modpow(a, (q + 1) >> 1, p);
    if (t == 0) return 0;
    m -= 2;
    while (t != 1) {
        while (modpow(t, int64_t(1) << m, p) == 1) {
            c = c * c % p;
            m--;
        }
        r = r * c % p;
        c = c * c % p;
        t = t * c % p;
        m--;
    }
    return r;
}