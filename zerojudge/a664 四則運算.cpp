#include <iostream>
#include <vector>
using namespace std;

long long calc(char *begin, char *end) {
    vector<long long> val;
    vector<char> oper;
    for (char *p = begin; p != end; p++) {
        if (*p == '(') {
            char *pp = p + 1;
            int cc = 1;
            while (cc > 0) {
                p++;
                if (*p == '(') {
                    cc++;
                }
                if (*p == ')') {
                    cc--;
                }
            }
            val.push_back(calc(pp, p));
        } else if (isdigit(*p)) {
            long long d;
            for (d = 0; p != end && isdigit(*p); p++) {
                d = d * 10 + (*p - '0');
            }
            p--;
            val.push_back(d);
        } else {
            oper.push_back(*p);
            continue;
        }
        if (!oper.empty()) {
            if (oper.back() == '*') {
                long long tmp = val.back();
                val.pop_back();
                val.back() *= tmp;
                oper.pop_back();
            } else if (oper.back() == '/') {
                long long tmp = val.back();
                val.pop_back();
                val.back() /= tmp;
                oper.pop_back();
            }
        }
    }
    while (!oper.empty()) {
        long long tmp = val.back();
        val.pop_back();
        if (oper.back() == '+') {
            val.back() += tmp;
        } else {
            val.back() -= tmp;
        }
        oper.pop_back();
    }
    return val.back();
}

int main() {
    int task;
    cin >> task;
    while (task--) {
        char s[128];
        cin >> s;
        int sl;
        for (sl = 0; s[sl]; sl++) {}
        cout << calc(s, s + sl) << endl;
    }
}
