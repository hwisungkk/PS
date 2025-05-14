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
string s;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    long long n, m, t, k;
    bool flag=1; 

    string s;
    cin >> n;
    cin >> s;

    int ans=0;
    int s_cnt=0, l_cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='S')s_cnt++;
        else if(s[i]=='L')l_cnt++;
        else if(s[i]=='R' && l_cnt>0){
            l_cnt--;
            ans++;
        }
        else if(s[i]=='K' && s_cnt>0){
            s_cnt--;
            ans++;
        }
        else if((s[i]=='R' && l_cnt==0) || s[i]=='K' && s_cnt==0){
            break;
        }
        else if(s[i]>='0' && s[i] <='9')ans++;
    }
    cout << ans;

    return 0;
}
