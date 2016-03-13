#include <bits/stdc++.h>
using namespace std;

class BigNum {
    public:
        BigNum(int _pc = 0) : pc(_pc), s(_pc + 1, 0) {}
        BigNum(int _pc, const BigNum &n) : pc(_pc) {
            for (int i = n.pc; i < pc; i++) {
                s += '\0';
            }
            int c = 0;
            for (int i = 0; i < (int) n.s.size(); i++) {
                if (n.pc - i <= pc) {
                    s += n.s[i];
                    s.back() += c;
                    c = 0;
                    if (s.back() >= 10) {
                        s.back() -= 10;
                        c = 1;
                    }
                } else if (n.pc - i == pc + 1) {
                    if (n.s[i] >= 5) {
                        c = 1;
                    }
                }
            }
            if (c) {
                s += 1;
            }
        }
        BigNum(const string &ins) {
            pc = 0;
            s.clear();
            for (int i = ins.size() - 1; i >= 0; i--) {
                if (ins[i] == '.') {
                    pc = ins.size() - i - 1;
                } else {
                    s += ins[i] - '0';
                }
            }
        }
        BigNum(int _pc, const string &ins) {
            *this = BigNum(_pc, BigNum(ins));
        }
        BigNum operator+(const BigNum &b) const {
            const BigNum &a = *this;
            BigNum r, k;
            if (a.pc > b.pc) {
                r = a;
                k.pc = a.pc;
                k.s.clear();
                for (int i = b.pc; i < a.pc; i++) {
                    k.s += '\0';
                }
                k.s += b.s;
            } else {
                r = b;
                k.pc = b.pc;
                k.s.clear();
                for (int i = a.pc; i < b.pc; i++) {
                    k.s += '\0';
                }
                k.s += a.s;
            }
            for (int i = r.s.size(); i < (int) k.s.size(); i++) {
                r.s += '\0';
            }
            for (int i = 0; i < (int) k.s.size(); i++) {
                r.s[i] += k.s[i];
            }
            r.prune();
            return r;
        }
        bool operator<=(const BigNum &b) const {
            const BigNum &a = *this;
            if (a.s.size() - a.pc > b.s.size() - b.pc) {
                return false;
            } else if (a.s.size() - a.pc < b.s.size() - b.pc) {
                return true;
            } else {
                int i, j;
                for (i = a.s.size() - 1, j = b.s.size() - 1; i >= 0 && j >= 0; i--, j--) {
                    if (a.s[i] < b.s[j]) {
                        return true;
                    } else if (a.s[i] > b.s[j]) {
                        return false;
                    }
                }
                while (i >= 0) {
                    if (a.s[i] > 0) {
                        return false;
                    }
                    i--;
                }
                while (j >= 0) {
                    if (b.s[j] > 0) {
                        return true;
                    }
                    j--;
                }
            }
            return true;
        }
        BigNum operator*(const BigNum &b) const {
            const BigNum &a = *this;
            BigNum r(a.pc + b.pc);
            for (int i = 0; i < (int) a.s.size(); i++) {
                BigNum tmp;
                tmp.s.clear();
                tmp.pc = a.pc + b.pc;
                for (int j = 0; j < i; j++) {
                    tmp.s += '\0';
                }
                for (int j = 0; j < (int) b.s.size(); j++) {
                    tmp.s += char(b.s[j] * a.s[i]);
                }
                tmp.prune();
                r = r + tmp;
            }
            return r;
        }
        BigNum sqrt() const {
            const BigNum &n = *this;
            BigNum l(n.pc), r = n, md = r;
            while (!((md = (l + r).half()) <= l)) {
                if (md * md <= n) {
                    l = md;
                } else {
                    r = md;
                }
            }
            return l;
        }

        friend istream &operator>>(istream &in, BigNum &n) {
            string tmp;
            in >> tmp;
            n = BigNum(n.pc, tmp);
            return in;
        }
        friend ostream &operator<<(ostream &out, const BigNum &n) {
            for (int i = n.s.size() - 1; i >= 0; i--) {
                out << char(n.s[i] + '0');
                if (i == n.pc && i != 0) {
                    out << '.';
                }
            }
            return out;
        }
    private:
        int pc;
        string s;
        BigNum half() {
            BigNum n = *this;
            for (int i = n.s.size(); i >= 0; i--) {
                if (i > 0 && (n.s[i] & 1)) {
                    n.s[i - 1] += 10;
                }
                n.s[i] /= 2;
            }
            n.prune();
            return n;
        }
        void prune() {
            for (int i = 0; i < (int) s.size(); i++) {
                if (s[i] >= 10) {
                    if (i + 1 == (int) s.size()) {
                        s += '\0';
                    }
                    s[i + 1] += s[i] / 10;
                    s[i] %= 10;
                }
            }
            while ((int) s.size() > pc + 1 && s.back() == 0) {
                s.pop_back();
            }
        }
};

int main() {
    BigNum a(60);
    while (cin >> a) {
        BigNum ans = BigNum(50, a.sqrt());
        cout << ans << endl;
    }
}
