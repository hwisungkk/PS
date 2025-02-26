#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    long long n, m, t;
    int total=0;
    cin >> n;

    // 1, 4, 9, 16, 25
    // 제곱수가 들어오면 무한함.
    // a^2 + b^2 = c^2
    // b^2에 들어갈 때 따로
    // 나머지는 a^2 + b^2 = c^2에서 c^2에 들어가야 하나? 이거는 투포인터로?

    m = int(sqrt(n)); //최대 10^6 (백만)
    if(m*m==n){
        cout << -1; // 제곱수면?
        return 0;
    }
    int ans = 0;

    //b^2 = c^2 - a^2

    //b^2 = c-a c+a ?

    for(int i=1;i<=m;i++){
        if(n%i==0){
            long long sum = i + n/i; //2c
            if(sum%2==0){
                if(sum/2-i == (n/i)-sum/2) {
                    ans++;
                }
            }
        }
    }


    long long l =1, r = m; //여기가 c^2에 들어갈 때
    while(l<=r){
        if(l*l + r*r == n){
            ans++;
            r--;
        }
        else if (l*l + r*r >n){
            r--;
        }
        else l++;
    }
    cout << ans;


    return 0;
}