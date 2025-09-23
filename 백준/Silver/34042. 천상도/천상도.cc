#define ll long long
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    long long a, b, c, d;
    long long ans = 0;
    using P = pair<int, int>;

    cin >> n >> m;

    while(m-->0){
        vector<int> v(5, 0);
        ans=0;
        ll ans1=1;
        ll ans2=1;
        for(int i=0;i<n;i++){
            cin >> a;
            v[a+2]++;
            if(a>0)ans1*=a;
            else if(a==0)continue;
            else ans2*=a;
        }
        if(v[3]+v[4]==0){ //1이나 2가 안나왔으면
            if(v[0]+v[1]<=1){
                if(v[2]>0){
                    ans=0;
                }
                else if(v[0]>0)ans=-2;
                else ans=-1;
            }
            else{
                if(ans2<0){
                    if(v[1]>=1){
                        ans=ans2*-1;
                    }
                    else ans=ans2/-2;
                }
                else ans=ans2;
            }
        }
        else{
            if(ans2<0){
                if(v[1]>=1){
                    ans2*=-1;
                }
                else ans2/=-2;
            }
            ans=ans1*ans2;
        }
        cout << ans << '\n';
    }
    
    return 0;
}