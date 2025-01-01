#include <stdio.h>

int main() {
    int a, b, c;
    int i = 0;
    scanf("%d", &a);
    while (a-- > 0) {
        i++;
        scanf("%d%d", &b, &c);
        printf("Case %d: %d\n",i, b + c);
    }
    return 0;
}