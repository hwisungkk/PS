#include <stdio.h>
#define max(a,b) a>b?a:b;
 
int main() {
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, x, s = 0, b = 0;
        scanf("%d%d", &n, &m);
        while (n--) {
            scanf("%d", &x), s = max(x, s);
        }
        while (m--) {
            scanf("%d", &x),
                b = max(x, b);
        }
        puts(s < b ? "B" : "S");
    }
    return 0;
}
