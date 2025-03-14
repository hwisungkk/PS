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
    
    cin >> n >> m;
    int time[100001]={0};
    for(int i=0;i<n;i++){
        cin >> t;
        for(int i=0;i<t;i++){
            cin >> a >> b;
            time[a]++;
            time[b]--;
        }
    }
    int cnt=0;
    int real_time[100001]={0};
    for(int i=0;i<=100000;i++){
        cnt += time[i];
        real_time[i]=cnt;
    }
    int ans=0;
    int l=0;
    int r=m;
    for(int i=0;i<m;i++){
        ans += real_time[i];
    }
    int max = ans;
    for(int i=m;i<=100000;i++){
        ans -= real_time[i-m];
        ans += real_time[i];
        if(max<ans){
            max = ans;
            l = i-m+1;
            r = i+1;
        }
    }
    cout << l << ' ' << r;
    return 0;
}