#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
vector<pair<int, int>> egg;
int t = 0;
int check[10]={0};
int cnt=0;
int ans=-1;
void back(int k){ //k를 집는 계란으로 하자
    // for(int i=0;i<t;i++){
    //     cout << egg[i].first << ' ' << egg[i].second << '\n';
    // }
    // cout << "count : " << cnt << '\n';
    if(check[k]==1){
        back(k+1);
        return;
    }
    ans = max(ans, cnt);
    if(k>=t){
        return;
    }
    for(int i=0;i<t;i++){
        if(k!=i && check[i]==0){
            egg[k].first-=egg[i].second;
            egg[i].first-=egg[k].second;
            if(egg[k].first<=0){
                check[k]=1;
                cnt++;
            }
            if(egg[i].first<=0){
                check[i]=1;
                cnt++;
            }
            back(k+1);
            egg[k].first+=egg[i].second;
            egg[i].first+=egg[k].second;
            if(egg[k].first>0 && check[k]==1){
                check[k]=0;
                cnt--;
            }
            if(egg[i].first>0 && check[i]==1){
                check[i]=0;
                cnt--;
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k;
    int a, b, c;

    cin >> t;
    for(int i=0;i<t;i++){
        cin >> a >> b;
        egg.push_back({a,b});
    }
    back(0);
    cout << ans;
    return 0;
}