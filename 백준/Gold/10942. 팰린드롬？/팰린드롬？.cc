#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    int chk=0;
    
    cin >> n;
    vector<int> v(n+1);
    int ans[2001][2001]={0};

    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        int l=i, r=i;
        ans[l][r]=1;
        chk = 1;
        while(1){
            l--;
            r++;
            if(l<=0 || r>n)break;
            if(chk && v[l]==v[r])ans[l][r]=1;
            else {
                ans[l][r] = 0;
                chk=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        int l=i, r=i+1;
        if(v[l]==v[r]){
            ans[l][r]=1;
            chk = 1;
        }
        else{
            ans[l][r]=0;
            chk = 0;
        }
        while(1){
            l--;
            r++;
            if(l<=0 || r>n)break;
            if(chk && v[l]==v[r])ans[l][r]=1;
            else {
                ans[l][r] = 0;
                chk=0;
            }
        }
    }
    cin >> t;
    while(t-->0){
        cin >> a >> b;
        cout << ans[a][b] << '\n';
    }


    return 0;
}