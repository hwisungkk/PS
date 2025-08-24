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
    
    vector<vector<int>> v(n, vector<int>(3));

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> v[i][j];
        }
    }

    int ans=1e9;

    for(int i=0;i<n;i++){
        int mi = 1e9;
        int mi2 = 1e9;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            else{
                int tt=0;
                for(int x=0;x<3;x++){
                    tt+=abs(v[i][x]-v[j][x]);
                }
                mi = min(mi, tt);
                if(mi2>mi)swap(mi, mi2);
            }
        }
        ans = min(ans, mi+mi2);
    }
    cout << ans;

    return 0;
}
