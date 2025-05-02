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
    long long n, m, t;
    bool flag=1; 
    
    cin >> n;
    string s;
    cin >> s;

    int cnt =1;
    for(int i=1;i<n;i++){
        if(s[i]==s[0]){
            flag = 1;
            int tmp = 0;
            for(int j=i;j<i+n;j++){
                if(j>=s.size()){
                    s+=s[tmp];
                }
                if(s[j]!=s[tmp]){
                    flag=0;
                    break;
                }
                tmp++;
            }
            if(flag)cnt++;
        }
    }
    cout << cnt;

    return 0;
}