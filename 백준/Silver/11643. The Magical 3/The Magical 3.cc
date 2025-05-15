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
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    long long n, m, t, k;
    bool flag=1; 

    string s;

    while(1){
        cin >> n;
        flag = 0;
        if(n==0)break;

        if(n==3)cout << "4\n";
        else if(n>=1 && n<=6)cout<<"No such base\n";
        else if(n==9) cout << "6\n";
        else if(n==12) cout << "9\n";
        else{
            a = max(4, int(sqrt(n)+2));
            n-=3;
            for(int i=4;i<=a;i++){
                if(n%i==0){
                    cout << i << '\n';
                    flag=1;
                    break;
                }
            }
            if(!flag){
                if(n%2==0) cout << n/2 << '\n';
                else if(n%3==0) cout << n/3 << '\n';
                else cout << n << '\n';
            }
        }
    }

    return 0;
}
