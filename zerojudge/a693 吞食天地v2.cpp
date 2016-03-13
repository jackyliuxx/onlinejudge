#include <cstdio>
using namespace std;
int main() {
    int n, m;
    int a[110000];
    while (~scanf("%d%d", &n, &m)) {
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            a[i] += a[i-1];
        }
        while (m--) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", a[r] - a[l-1]);
        }
    }
}
