#include<bits/stdc++.h>
using namespace std;

vector<int> build_fail(const string& s){
    vector<int> fail;
    fail.push_back(-1);
    for(int i = 1, j = -1; i < (int) s.size(); i++){
        while(j >= 0 && s[j+1] != s[i])
            j = fail[j];
        if(s[j+1] == s[i])
            j++;
        fail.push_back(j);
    }
    return fail;
}
int match(const string& a, const string& b, const vector<int> &fail){
    int lenth;
    for(int i = 0, j = -1; i < (int) a.size(); i++){
        while(j >= 0 && b[j+1] != a[i])
            j = fail[j];
        if(b[j+1] == a[i])
            j++;
        if( i == (int) a.size() - 1 ) {
            lenth = j + 1;
        }
    }
    return lenth;
}

int main(){
    string s;
    while ( cin >> s ) {
        string s2(s);
        reverse(s2.begin(), s2.end());
        vector<int> fail = build_fail(s2);
        int lenth = match(s, s2, fail);
        s.append(s2.substr(lenth));
        cout << s << endl;
    }
}       
