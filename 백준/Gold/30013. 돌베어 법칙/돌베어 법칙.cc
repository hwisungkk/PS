#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;

    cin >> n;
    string s;
    cin >> s;

    int ma=1e6;
    for(int i=1;i<=n-1;i++){
        vector<bool> chk(n,0);
        int cnt=0;
        for(int j=0;j<n;j++){
            if(s[j]=='#' && chk[j]==0){
                cnt++;
                k=j;
                while(s[k]=='#'){
                    k+=i;
                    if(k>=n)break;
                    chk[k]=1;
                }

            }
        }
        ma=min(ma, cnt);
    }
    cout << ma;

    return 0;
}
