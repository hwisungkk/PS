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
    
    int n, m, t;
    int a, b, c;
    cin >> t;
    cin >> n;
    vector<int> v1(n);
    for(int i=0;i<n;i++){
        cin >> v1[i];
    }
    cin >> m;
    vector<int> v2(m);
    for(int i=0;i<m;i++){
        cin >> v2[i];
    }
    int total=0;
    for(int i=0;i<n-1;i++){
        total=v1[i];
        for(int j=i+1;j<n;j++){
            total+=v1[j];
            v1.push_back(total);
        }
    }
    for(int i=0;i<m-1;i++){
        total=v2[i];
        for(int j=i+1;j<m;j++){
            total+=v2[j];
            v2.push_back(total);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    long long ans=0;

    int l = 0;
    int r = v2.size()-1;

    while(l<v1.size() && r >= 0){
        long long d_r=1;
        long long d_l=1;
        if(v1[l]+v2[r]<t){
            l++;
        }
        else if(v1[l]+v2[r]>t){
            r--;
        }
        else{
            while(r>0 && v2[r]==v2[r-1]){
                r--;
                d_r++;
            }
            while(l<v1.size()-1 && v1[l]==v1[l+1]){
                l++;
                d_l++;
            }
            ans += d_l * d_r;
            r--;
        }
    }

    cout << ans;
    return 0;
}