#include <bits/stdc++.h>
using namespace std;

vector<string> rev(const vector<string> v) {
    vector<string> rt;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == "and") {
            rt.push_back("or");
        } else if (v[i] == "or") {
            rt.push_back("and");
        } else if (v[i] != "not") {
            if (i > 0 && v[i - 1] == "not") {
                rt.push_back(v[i]);
            } else {
                rt.push_back("not");
                rt.push_back(v[i]);
            }
        }
    }
    return rt;
}

int main() {
    int n;
    cin >> n >> ws;
    while (n--) {
        string tmp;
        getline(cin, tmp);
        stringstream ss(tmp);
        vector<string> A, B;
        ss >> tmp;
        while (ss >> tmp && tmp != "THEN") {
            A.push_back(tmp);
        }
        while (ss >> tmp) {
            B.push_back(tmp);
        }
        A = rev(A);
        B = rev(B);
        cout << "IF";
        for (auto i : B) {
            cout << ' ' << i;
        }
        cout << " THEN";
        for (auto i : A) {
            cout << ' ' << i;
        }
        cout << endl;
    }
}
