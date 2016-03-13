#include <bits/stdc++.h>
using namespace std;

string NAND(const string &a, const string &b) {
    return "(" + a + "|" + b + ")";
}

string AND(const string &a, const string &b) {
    return NAND(NAND(a, b), NAND(a, b));
}

string OR(const string &a, const string &b) {
    return NAND(NAND(a, a), NAND(b, b));
}

string C1(int n) {
    string a = "A" + to_string(n);
    string b = "B" + to_string(n);
    if (n == 0) {
        return AND(a, b);
    } else {
        return OR(AND(a, b), AND(OR(a, b), C1(n - 1)));
    }
}

string C2(int n) {
    string a = "A" + to_string(n);
    string b = "B" + to_string(n);
    if (n == 0) {
        return AND(a, b);
    } else {
        return NAND(NAND(a, b), NAND(C2(n - 1), OR(a, b)));
    }
}

int count(const string &s) {
    int r = 0;
    for (auto i : s) {
        if (i == '|') r++;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    string ans1, ans2;
    cout << "ans1:" << endl;
    ans1 = C1(n);
    cout << ans1 << endl;
    cout << count(ans1) << " NAND(s) used." << endl;
    cout << "ans2:" << endl;
    ans2 = C2(n);
    cout << ans2 << endl;
    cout << count(ans2) << " NAND(s) used." << endl;
}
