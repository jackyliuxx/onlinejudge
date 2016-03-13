#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class bigint {
    public:
        bigint() : s() {}
        bigint(const bigint &b) : s(b.s) {}

        bigint operator/(const bigint &b) {
            bigint c = *this, r;
            for ( int i = c.s.size() - b.s.size(); i >= 0; i-- ) {
                r.s.push_back('0');
                while ( bt(c.s, b.s, i) ) {
                    for ( int j = 0; j < (int) b.s.size(); j++ ) {
                        c.s[i + j] -= b.s[j] - '0';
                        if ( c.s[i + j] < '0' ) {
                            c.s[i + j] += 10;
                            c.s[i + j + 1] -= 1;
                        }
                    }
                    r.s.back() += 1;
                }
            }
            reverse(r.s.begin(), r.s.end());
            while ( r.s.back() == '0' ) {
                r.s.pop_back();
            }
            return r;
        }
        bigint operator%(const bigint &b) {
            bigint c = *this;
            for ( int i = c.s.size() - b.s.size(); i >= 0; i-- ) {
                while ( bt(c.s, b.s, i) ) {
                    for ( int j = 0; j < (int) b.s.size(); j++ ) {
                        c.s[i + j] -= b.s[j] - '0';
                        if ( c.s[i + j] < '0' ) {
                            c.s[i + j] += 10;
                            c.s[i + j + 1] -= 1;
                        }
                    }
                }
            }
            while ( c.s.back() == '0' ) {
                c.s.pop_back();
            }
            return c;
        }
        friend istream &operator>>(istream &in, bigint &bi) {
            in >> bi.s;
            reverse(bi.s.begin(), bi.s.end());
            return in;
        }
        friend ostream &operator<<(ostream &out, const bigint &bi) {
            for ( auto i = bi.s.rbegin(); i != bi.s.rend(); i++ ) {
                out << *i;
            }
            if ( bi.s.empty() ) {
                out << 0;
            }
            return out;
        }
    private:
        bool bt(const string &a, const string &b, int p) {
            if ( a.size() > p + b.size() - 1 && a[p + b.size()] > '0' ){
                return true;
            }
            for ( int i = b.size() - 1; i >= 0; i-- ) {
                if ( a[p + i] > b[i] ) { return true; }
                if ( a[p + i] < b[i] ) { return false; }
            }
            return true;
        }
        string s;
};

int main() {
    bigint a, b;
    while ( cin >> a >> b ) {
        cout << a / b << "    " << a % b << endl;
    }
}
