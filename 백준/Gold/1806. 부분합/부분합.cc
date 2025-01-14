#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int n, m, k;
    int t;
    int mi = 1e9;
    string s;
    cin >> n >> m;
    int total=0;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        total += v[i];
    }
    int l = 0;
    int r = 1;
    if(total<m)mi=0;
    if(v[0]>=m)mi=1;
    total=v[0]+v[1];
    while(r<n && l<r){
        if(total<m){
            r++;
            total += v[r];
        }
        else{
            total -=v[l];
            l++;
        }
        if(total>=m){
            mi=min(mi, r-l+1);
        }
    }
    cout << mi;
    return 0;
}
