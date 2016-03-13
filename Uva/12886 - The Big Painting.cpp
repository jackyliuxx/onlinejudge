#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int B1 = 7, B2 = 11, M = 1000000007, MAXN = 2048;
long long B1p[MAXN], B2p[MAXN];

void init(){
    B1p[0] = 1;
    for(int i = 1; i < MAXN; i++)
        B1p[i] = B1p[i - 1] * B1 % M;
    B2p[0] = 1;
    for(int i = 1; i < MAXN; i++)
        B2p[i] = B2p[i - 1] * B2 % M;
}

vector< vector<int> > rh(const vector<string> &s){
    vector< vector<int> > v(1, vector<int>(s[0].size()+1, 0));
    for(int i = 0; i < (int) s.size(); i++){
        v.push_back(vector<int>(1, 0));
        for(int j = 0; j < (int) s[i].size(); j++){
            v[i+1].push_back((v[i+1][j] + v[i][j+1] - v[i][j] + s[i][j] * B1p[i] * B2p[j] + M) % M);
        }
    }
    return v;
}

inline bool same(int bhv, const vector< vector<int> > &ahv_list, int i, int j, int h, int w){
    return ((long long)ahv_list[i + h][j + w] - ahv_list[i + h][j] - ahv_list[i][j + w] + ahv_list[i][j] + 2 * M) % M == bhv * B1p[i] % M * B2p[j] % M;
}

int main(){
    init();
    int h1, w1, h2, w2;
    while(cin >> h1 >> w1 >> h2 >> w2){
        vector<string> b, a;
        string s;
        for(int i = 0; i < h1; i++){
            cin >> s;
            b.push_back(s);
        }
        for(int i = 0; i < h2; i++){
            cin >> s;
            a.push_back(s);
        }
        for(int i = 0; i < (int) b.size(); i++)
            for(int j = 0; j < (int) b[i].size(); j++)
                b[i][j] = b[i][j] == 'o' ? 1 : 0;
        for(int i = 0; i < (int) a.size(); i++)
            for(int j = 0; j < (int) a[i].size(); j++)
                a[i][j] = a[i][j] == 'o' ? 1 : 0;
        int bhv = rh(b).back().back();
        vector< vector<int> > ahv_list = rh(a);
        int ans = 0;
        for(int i = 0; i < (int) a.size() - h1 + 1; i++){
            for(int j = 0; j < (int) a[i].size() - w1 + 1; j++){
                if(same(bhv, ahv_list, i, j, h1, w1))
                    ans++;
            }
        }
        cout << ans << endl;
    }
}
