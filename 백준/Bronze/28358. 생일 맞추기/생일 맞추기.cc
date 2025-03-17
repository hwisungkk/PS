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
    int n, m, t;
    char ch;
    bool flag=0;
    
    cin >> t;
    while(t-->0){
        int ans=0;
        vector<int> v(10, 0);
        for(int i=0;i<10;i++){
            cin >> v[i];
        }
        for(int i=1;i<=12;i++){
            if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)b=31;
            else if(i==2)b=29;
            else b=30;
            for(int j=1;j<=b;j++){
                if(j<10)c=i*10+j;
                else c = i*100+j;
                flag = 0;
                while(c){
                    if(v[c%10]){
                        flag=1;
                    }
                    c/=10;
                }
                if(!flag){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    

    return 0;
}