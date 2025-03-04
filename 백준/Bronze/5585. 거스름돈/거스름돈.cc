#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
long long gcd(long long a, long long b){
    if(a<b)swap(a,b);
    while(b){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, k, t;
    int o_1, o_2;

    cin >> n;
    int mo = 1000-n;
    int ans=0;

    while(mo){
        if(mo>=500){
            mo-=500;
            ans++;
        }
        else if(mo>=100){
            mo-=100;
            ans++;
        }
        else if(mo>=50){
            mo-=50;
            ans++;
        }
        else if(mo>=10){
            mo-=10;
            ans++;
        }
        else if(mo>=5){
            mo-=5;
            ans++;
        }
        else if(mo>=1){
            mo-=1;
            ans++;
        }
    }

    cout << ans;

    return 0;
}