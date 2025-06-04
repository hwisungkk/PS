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
    int a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;
    int cur = 0;

    while(1){
        string s1, s2;

        cin >> s1;
        if(s1=="0"){
            cout << ans << '\n';
            ans=0;
            continue;
        }
        if(s1=="#"){
            break;
        }
        char ch;
        cin >> s2 >> n >> ch;

        if(ch=='Y'){
            if(n<500)n=500;
            ans+=n;
        }
        else if(ch=='B'){
            n*=3;
            n++;
            n/=2;
            //if(n<500)n=500;
            ans+=n;
        }
        else if(ch=='F'){
            n*=2;
            //if(n<500)n=500;
            ans+=n;
        }
    }

    return 0;
}

