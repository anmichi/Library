#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class S, S (*op)(S, S), S (*e)(), bool persistent>
struct dynamic_segtree {
    struct Node {
        S x;
        Node *l, *r;
    };
    ll L0, R0;
    vector<Node*> roots;
    dynamic_segtree() = default;
    dynamic_segtree(ll L0, ll R0) : L0(L0), R0(R0) { roots.push_back(new_node()); }
    dynamic_segtree(const vector<S>& a) : L0(0), R0(int(a.size())) { roots.push_back(build(L0, R0, a)); }
    S prod(Node* root, ll l, ll r) {
        assert(L0 <= l && l <= r && r <= R0);
        if (l == r) return e();
        S x = e();
        prod(root, l, r, L0, R0, x);
        return x;
    }
    S prod(int t, ll l, ll r) { return prod(roots[t], l, r); }
    S prod(ll l, ll r) { return prod(roots.back(), l, r); }
    S get(Node* root, ll k) {
        assert(L0 <= k && k < R0);
        return get(root, k, L0, R0);
    }
    S get(int t, ll k) { return get(roots[t], k); }
    S get(ll k) { return get(roots.back(), k); }
    void set(Node*& root, ll k, S x) {
        root = copy_node(root);
        set(root, L0, R0, k, x);
    }
    void set(int t, ll k, S x) { set(roots[t], k, x); }
    void set(int k, S x) { set(roots.back(), k, x); }
    void duplicate(Node* root) {
        assert(persistent);
        roots.push_back(root);
    }
    void duplicate(int t) { duplicate(roots[t]); }
    void duplicate() { duplicate(roots.back()); }

   private:
    void prod(Node* node, ll a, ll b, ll l, ll r, S& x) {
        if (!node) return;
        a = max(a, l);
        b = min(b, r);
        if (a >= b) return;
        if (a == l && b == r) {
            x = op(x, node->x);
            return;
        }
        ll m = (l + r) / 2;
        prod(node->l, a, b, l, m, x);
        prod(node->r, a, b, m, r, x);
    }

    S get(Node* node, ll k, ll l, ll r) {
        if (!node) return e();
        if (r - l == 1) return node->x;
        ll m = (l + r) / 2;
        if (k < m) return get(node->l, k, l, m);
        return get(node->r, k, m, r);
    }

    void set(Node* node, ll l, ll r, ll k, const S& x) {
        if (r == l + 1) {
            node->x = x;
            return;
        }
        ll m = (l + r) / 2;
        if (k < m) {
            node->l = copy_node(node->l);
            set(node->l, l, m, k, x);
        } else {
            node->r = copy_node(node->r);
            set(node->r, m, r, k, x);
        }
        S vl = (node->l ? node->l->x : e());
        S vr = (node->r ? node->r->x : e());
        node->x = op(vl, vr);
    }
    Node* copy_node(Node* node) {
        if (!node) return new_node();
        if (!persistent) return node;
        return new Node{node->x, node->l, node->r};
    }
    Node* new_node() { return new Node{e(), nullptr, nullptr}; }
    Node* merge(Node* l, Node* r) { return new Node{op(l->x, r->x), l, r}; }
    Node* build(ll l, ll r, const vector<S>& v) {
        if (l + 1 == r) return new Node{v[l], nullptr, nullptr};
        ll m = (l + r) / 2;
        return merge(build(l, m, v), build(m, r, v));
    }
};