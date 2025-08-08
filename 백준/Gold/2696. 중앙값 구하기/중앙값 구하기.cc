#define ll long long
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
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    cin >> t;
    while(t-->0){
        cin >> n;
        vector<ll> ans;
        priority_queue<ll> pq1; // 절반 이하가 담기기
        priority_queue<ll,vector<ll>,greater<ll>> pq2; // 작은거가 우선임 -> 절반 이상
        for(int i=0;i<n;i++){
            cin >> a;
            if(pq1.size()==pq2.size() && pq1.size()==0){
                pq1.push(a);
            }
            else if(pq1.size()>pq2.size()){
                if(a>=pq1.top()){
                    pq2.push(a);
                }
                else{
                    pq1.push(a);
                    pq2.push(pq1.top());
                    pq1.pop();
                }
            }
            else{
                if(pq1.top()>=a){
                    pq1.push(a);
                }
                else{
                    pq2.push(a);
                    pq1.push(pq2.top());
                    pq2.pop();
                }
            }
            if(i%2==0){
                ans.push_back(pq1.top());
            }
        }
        cout << ans.size();
        for(int i=0;i<ans.size();i++){
            if(i%10==0)cout<<'\n';

            if(i%10==9)cout<<ans[i];
            else if(i==ans.size()-1)cout << ans[i];
            else cout << ans[i] << ' ';
        }
        cout << '\n';

    }

    return 0;
}