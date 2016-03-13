#include <iostream>
#include <vector>
using namespace std;

template<class T>
class SegTree {
    private:
        class Node {
            public:
                T v;
                Node *l, *r;
                int size;
                Node() : v(), l(NULL), r(NULL), size(1) {}
        };
        void build(T *data, int size, Node *node) {
            if ( size == 1 ) {
                node->v = *data;
            } else {
                node->l = new Node;
                node->r = new Node;
                build(data, size/2, node->l);
                build(data, data+size/2, node->r);
                node->v = node->l->v + node->r->v;
            }
            node->size = size;
        }
        Node *root;
    public:
        SegTree() : root(NULL) {}
        SegTree(const vector<T> &vec) {
            build(vec.begin(), vec.size(), root);
        }
        int size() {
            return root->size;
        }
        T sum(int l, int r) {
            sum(l, r, root);
        }
        T sum(int l, int r, Node *node) {
            if ( l == 0 && r == node->size ) {
                return node->v;
            } else {
                if ( l < node->size / 2 ) {
                    if ( r > node->size / 2) {
                        return sum(l, node->size / 2, node->l) + sum(0, r - node->size / 2, node->r);
                    } else {
                        return sum(l, r, node->l);
                    }
                } else {
                    return sum(l - node->size / 2, r - node->size / 2, node->l);
                }
            }
        }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    for ( int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    SegTree<int> st = vec;
    for ( int i = 0; i < m; i ++ ) {
        int l, r;
        cin >> l >> r;
        cout << st.sum(l, r) << endl;
    }
}
