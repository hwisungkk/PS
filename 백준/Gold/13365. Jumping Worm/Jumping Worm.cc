#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1'000'000'007;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    cin >> t;
    while(t-->0){
        cin >> n;
        vector<int> high(n);
        vector<int> up(n);
        vector<int> down(n);
        for(int i=0;i<n;i++)cin>>high[i];
        for(int i=0;i<n;i++)cin>>up[i];
        for(int i=0;i<n;i++)cin>>down[i];

        vector<vector<int>> chk(n, vector<int>(1001, 1e8));

        queue<pair<int,int>> q;
        q.push({0,0});
        chk[0][0]=0;

        pair<int,int> p;

        while(!q.empty()){
            p=q.front();
            //cout<< p.first << ' ' << p.second << '\n';
            q.pop();

            //위로, 오른쪽, 왼쪽이 필요한가?, 밑에는 없는듯?
            if(p.second+up[p.first]>=high[p.first]){
                if(chk[p.first][p.second]+1<chk[p.first][high[p.first]]){ // 위로 갔는데 높이보다 높거나 같음
                    chk[p.first][high[p.first]] = chk[p.first][p.second]+1;
                    q.push({p.first, high[p.first]});
                }
            }
            //위로 갔는데 높이보다 낮음. 이러면 떨어져야 함.
            else if(p.second+up[p.first]-down[p.first]<=0){
                if(chk[p.first][p.second]+2<chk[p.first][0]){
                    chk[p.first][0] = chk[p.first][p.second]+2;
                    q.push({p.first, 0});
                }
            }
            else if(chk[p.first][p.second]+2<chk[p.first][p.second+up[p.first]-down[p.first]]){
                chk[p.first][p.second+up[p.first]-down[p.first]] = chk[p.first][p.second]+2;
                q.push({p.first, p.second+up[p.first]-down[p.first]});
            }

            if(p.first+1<n){
                if(p.second>=high[p.first+1]){ // 꼭대기로 갈 때
                    if(chk[p.first][p.second]+1<chk[p.first+1][high[p.first+1]]){
                        chk[p.first+1][high[p.first+1]]=chk[p.first][p.second]+1;
                        q.push({p.first+1, high[p.first+1]});
                    }
                }
                else if(chk[p.first][p.second]+2<chk[p.first+1][max(0, p.second-down[p.first+1])]){
                    chk[p.first+1][max(0, p.second-down[p.first+1])]=chk[p.first][p.second]+2;
                    q.push({p.first+1, max(0, p.second-down[p.first+1])});
                }
            }
        }

        if(chk[n-1][high[n-1]]==1e8)cout<<"NEVER\n";
        else cout << chk[n-1][high[n-1]]<<'\n';

    }

    return 0;
}