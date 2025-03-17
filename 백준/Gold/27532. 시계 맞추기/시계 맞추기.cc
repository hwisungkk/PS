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
    
    cin >> n;
    int mx = 1e9;
    string s;
    vector<int> time(n);
    for(int i=0;i<n;i++){
        cin >> s;
        time[i] = int(s[0]-48)*600 + int(s[1]-48)*60 + int(s[3]-48)*10 + int(s[4]-48);
        // moduler 720
    }
    int mi;
    for(int i=1;i<=720;i++){
        int ans=0;
        vector<bool> check(720, 0);
        for(int j=0;j<n;j++){
            b = (time[j]-(i*j))%720;
            if(b<0)b+=720;
            if(check[b]==0){
                check[b]=1;
                ans++;
            }
        }
        mi = min(mi, ans);
    }
    cout << mi;
    return 0;
}
    
    
    

