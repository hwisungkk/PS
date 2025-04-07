#include <stdio.h>
#include <limits.h>
 
int main() {
    int t;
    scanf("%d", &t);
    int a, b, c;
    int max = INT_MIN;
    while (t-->0)
    {
        int cost = 0;
        scanf("%d %d %d", &a, &b, &c);
        if (a == b && b == c && a==c)
        {
            cost = 10000 + a * 1000;
        }
        else if(a==b&&a!=c&&b!=c)
        {
            cost = 1000 + a * 100;
        }
        else if (a == c && a != b && b != c)
        {
            cost = 1000 + a * 100;
        }
        else if (c == b && a != c && b != a)
        {
            cost = 1000 + b * 100;
        }
        else
        {
            int cnt;
            cnt = (a > b) ? a : b;
            cnt = (cnt > c) ? cnt : c;
            cost = cnt * 100;
        }
        if (max < cost)
        {
            max = cost;
        }
    }
    printf("%d", max);
}
