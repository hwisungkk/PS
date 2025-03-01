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
    int n, m, t;
    cin >> n;
    long long ans = 0;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin >> m;
        if(v.size()==0){

        }
        else{
            if(m>v[v.size()-1]){
                int l = 0, r = v.size()-1;
                while(l+1<r){
                    int mid = (l+r)>>1; //내림차 순으로 정렬되어 있음.
                    if(v[mid]<=m) r = mid;
                    else l = mid;
                }
                ans += (v.size() - l);
                while(v.size() && v[v.size()-1] < m){
                    v.pop_back();
                }
            }
            else if(m==v[v.size()-1]){
                int l = 0, r = v.size()-1;
                while(l+1<r){
                    int mid = (l+r)>>1; //내림차 순으로 정렬되어 있음.
                    if(v[mid]==m) r = mid;
                    else l = mid;
                }
                ans += (v.size() - l);
            }
            else if(m<v[v.size()-1]){
                ans +=1;
            }
        }
        v.push_back(m);
        // for(int i=0;i<v.size();i++){
        //     cout << v[i] << ' ';
        // }cout << '\n';
        // cout << "ans : " << ans << '\n';
    }
    cout << ans;

    return 0;
}