#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
        class Node{
            public:
                int cnt, depth;
                Node *child[10];
                Node(int _depth = 0){
                    cnt = 0;
                    depth = _depth;
                    memset(child, 0, sizeof(child));
                }
        };

        Node *root, *pool;
        int pp;

        Trie(){
            pool = new Node[1048576];
            pp = 0;
            root = &pool[pp++];
        }

        ~Trie(){
            delete pool;
        }

        void insert(const string &s, Node *nd = NULL , int pos = 0){
            if(nd == NULL)
                nd = root;
            if(pos >= (int) s.size()){
                nd->cnt++;
                return;
            }
            int c = s[pos] - '0';
            if(nd->child[c] == NULL){
                pool[pp] = Node(nd->depth + 1);
                nd->child[c] = &pool[pp++];
            }
            insert(s, nd->child[c], pos+1);
        }

        bool consistent() {
            return consistent(root);
        }

        bool consistent(Node *nd) {
            if ( nd == NULL ) {
                return true;
            }
            for ( int i = 0; i < 10; i++ ){
                if ( nd->child[i] ) {
                    if ( nd->cnt > 0 )
                        return false;
                    else if ( !consistent(nd->child[i]) )
                        return false;
                }
            }
            return true;
        }   
};

int main(){
    int t;
    cin >> t;
    while ( t-- ) {
        int n;
        cin >> n;
        Trie t;
        for ( int i = 0; i < n; i++ ) {
            string s;
            cin >> s;
            t.insert(s);
        }
        if( t.consistent() )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
