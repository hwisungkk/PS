#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m;
    int a, b, c;

    int t;
    int i=0;
    cin >> t;
    while(t-->0){
        i++;
        cin >> n >> m;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        int ans=0;
        int l=0, r=n-1;
        while(l<r){
            if(v[l]+v[r]<=m){
                l++;
                r--;
            }
            else{
                r--;
            }
            ans++;
        }
        if(l==r)ans++;

        cout << "Case #" << i << ": " << ans << '\n';
    }

    return 0;
}