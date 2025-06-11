#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    cin >> a >> b;
    if(a<b)swap(a,b); //a가 더 크게게

    n=1000000000;
    string s="";
    if(a==0&&b==0){
        cout<<"0";
        return 0;
    }

    while(n!=0){
        if(a/n==0 && b/n==0){
            if(ans==1)s+="0";
        }else if(a/n!=0 && b/n==0){
            if(a/n<=2)s+="0";
            else s+="9";
            a%=n;
            ans=1;
        }else{
            if((a/n<=2&&b/n<=2) || (a/n>=7&&b/n>=7)){
                s+="0";
            }else s+="9";
            a%=n;
            b%=n;
            ans=1;
        }
        n/=10;
    }
    cout << s;

    return 0;
}

