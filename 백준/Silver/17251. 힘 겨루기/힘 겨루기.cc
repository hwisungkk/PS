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
        
    int a, b=0, c, d;
    long long n, m, t;
    bool flag=1; 
    
    cin >> n;
    int r=0;
    vector<int> v(n);
    int ma = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> pre(n);
    vector<int> suf(n);

    pre[0] = v[0];
    for(int i=1;i<n;i++){
        pre[i] = max(pre[i-1], v[i]);
    }
    suf[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i] = max(suf[i+1], v[i]);
    }

    for(int i=0;i<n-1;i++){
        if(pre[i]<suf[i+1])b++;
        else if (pre[i]>suf[i+1])r++;
    }
    if(b<r)cout <<"R";
    else if(b==r)cout << "X";
    else cout << "B";

    return 0;
}