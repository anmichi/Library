// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/117
#include "../Binomial.cpp"
#include "../modint.cpp"
int main() {
    Binomial<modint<1000000007>> bin(2000000);
    int t;
    scanf("%d", &t);
    while (t--) {
        char op;
        int n, k;
        scanf("\n%c(%d,%d)", &op, &n, &k);
        if (op == 'C') printf("%d\n", bin.C(n, k).val());
        if (op == 'P') printf("%d\n", bin.P(n, k).val());
        if (op == 'H') printf("%d\n", bin.H(n, k).val());
    }
}