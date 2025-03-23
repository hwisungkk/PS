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
    
    int a, b, c, d;
    int n, m, t;
    char ch;
    string s;
    int ans=0;
    bool flag=0;

    cin >> t;
    while(t-->0){
        vector<pair<int, pair<int, int>>> v;
        map <int,int> mp; //나온애 저장용?
        ans=0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a >> b;
            v.push_back({max(0, i-a), {1, b}}); //1은 집어넣는거
            v.push_back({min(n-1, i+a+1), {-1, b}}); //-1은 빼는거
        }
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        for(int i=0;i<v.size();i++){
            flag =0;
            if(i!=0 && v[i].first!=v[i-1].first){
                vector<int> tmp;
                while(pq.size()){
                    if(mp[pq.top()]==0)pq.pop(); //없으면
                    else{ //있으면
                        tmp.push_back(pq.top());
                        mp[pq.top()]--;
                        pq.pop();
                    }
                    if(tmp.size()==3){
                        ans = max(ans, tmp[0]+tmp[1]+tmp[2]);
                        pq.push(tmp[0]);
                        mp[tmp[0]]++;
                        pq.push(tmp[1]);
                        mp[tmp[1]]++;
                        pq.push(tmp[2]);
                        mp[tmp[2]]++;
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    for(int j=0;j<tmp.size();j++){
                        mp[tmp[j]]++;
                        pq.push(tmp[j]);
                    }
                }
            }
            if(v[i].second.first==1){
                pq.push(v[i].second.second);
                mp[v[i].second.second]++;
            }
            else if(v[i].second.first==-1){
                mp[v[i].second.second]--;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}