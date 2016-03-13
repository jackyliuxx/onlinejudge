#include <bits/stdc++.h>
using namespace std;

class BigInt {
    private:
        string s;
    public:
        BigInt() {}
        bool operator <=(const BigInt &b) const {
            const BigInt &a = *this;
            if (a.s.size() > b.s.size()) {
                return false;
            } else if (a.s.size() < b.s.size()) {
                return true;
            } else {
                for (int i = a.s.size() - 1; i >= 0; i--) {
                    if (a.s[i] > b.s[i]) {
                        return false;
                    } else if (a.s[i] < b.s[i]) {
                        return true;
                    }
                }
            }
            return true;
        }
        BigInt operator -(const BigInt &b) const {
            BigInt a = *this;
            for (size_t i = 0; i < b.s.size(); i++) {
                a.s[i] -= b.s[i] - '0';
                if (a.s[i] < '0') {
                    a.s[i + 1]--;
                    a.s[i] += 10;
                }
            }
            while (a.s.back() == '0') {
                a.s.pop_back();
            }
            return a;
        }
        BigInt operator /(const BigInt &b) const {
            BigInt a, rt;
            for (int i = this->s.size() - 1; i >= 0; i--) {
                rt.s = '0' + rt.s;
                a.s = this->s[i] + a.s;
                while (b <= a) {
                    a = a - b;
                    rt.s[0]++;
                }
            }
            while (rt.s.back() == '0') {
                rt.s.pop_back();
            }
            if (rt.s.empty()) {
                rt.s = "0";
            }
            return rt;
        }
        friend istream& operator>>(istream &in, BigInt &n) {
            in >> n.s;
            reverse(n.s.begin(), n.s.end());
            return in;
        }
        friend ostream& operator<<(ostream &out, const BigInt &n) {
            for (int i = n.s.size() - 1; i >= 0; i--) {
                cout << n.s[i];
            }
            return out;
        }
};

int main () {
    BigInt s1, s2;
    while (cin >> s1 >> s2) {
        cout << s1 / s2 << endl;
    }
}
