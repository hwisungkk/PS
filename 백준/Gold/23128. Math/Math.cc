#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    char ch;
    string s;
    long long ans=0;
    bool flag=0;

    cin >> n;
    vector<long long> v(n);
    vector<bool> check(1000001, 0);
    for(int i=0;i<n;i++){
        cin >> v[i];
        check[v[i]]=1;
    }
    for(int i=0;i<n;i++){
        t = 2*v[i]+1;
        a = 2*v[i]+3;
        while(t<=1000000){
            if(check[t])ans++;
            t+=a;
            a+=2;
        }
    }
    cout << ans;

    return 0;
}
// 5, 7, 9, 11

//1일때 제곱 만드는 애. 3, 8, 15, 24...
//2일 때 제곱 만드는 애 5, 12, 21, 32
//3일 때 7, 16, 27..
//4일 때 9, 