#include<bits/stdc++.h>
using namespace std;

int dp[5140][5140];

bool dpp(const string &s, int fr, int to) {
    if(to - fr <= 1)
        return 1;
    if(~dp[fr][to])
        return dp[fr][to];
    return dp[fr][to] = s[fr] == s[to - 1] && dpp(s, fr + 2, to - 2);
}   

class Trie{
    public:
        class Node{
            public:
                int cnt, depth, size;
                Node *child[2];
                Node(int _depth = 0){
                    cnt = 0;
                    depth = _depth;
                    size = 0;
                    memset(child, 0, sizeof(child));
                }
        };

        Node *root, *pool;
        int pp;

        Trie(){
            pool = new Node[13000000];
            pp = 0;
            root = &pool[pp++];
        }

        ~Trie(){
            delete pool;
        }

        void insert(const string &s, int bg, Node *nd = NULL , int pos = 0){
            if(nd == NULL)
                nd = root;
            if(pos == 0)
                pos = bg;
            if(pos > bg && dpp(s, bg, pos))
                nd->cnt++;
            if(pos >= (int) s.size()){
                nd->size = nd->cnt;
                if(nd->child[0])
                    nd->size += nd->child[0]->size;
                if(nd->child[1])
                    nd->size += nd->child[1]->size;
                return;
            }
            int c = s[pos] - 'a';
            if(nd->child[c] == NULL){
                pool[pp] = Node(nd->depth + 1);
                nd->child[c] = &pool[pp++];
            }
            insert(s, bg, nd->child[c], pos+1);
            nd->size = nd->cnt;
            if(nd->child[0])
                nd->size += nd->child[0]->size;
            if(nd->child[1])
                nd->size += nd->child[1]->size;
            return;
        }

        void _find(int k, Node *nd, string &s){
            if ( nd->cnt >= k)
                return;
            k -= nd->cnt;
            int lsize = nd->child[0] ? nd->child[0]->size : 0;
            if ( k <= lsize ) {
                s.push_back('a');
                _find(k, nd->child[0], s);
            }
            else {
                s.push_back('b');
                _find(k - lsize, nd->child[1], s);
            }
        }

        string find(int k) {
            string s;
            _find(k, root, s);
            return s;
        }
};

int main(){
    string s;
    while ( cin >> s ) {
        memset(dp, -1, sizeof(dp));
        int k;
        cin >> k;
        Trie t;
        for ( int i = 0; i < (int) s.size(); i++ ) {
            t.insert(s, i);
        }
        cout << t.find(k) << endl;
    }
}
