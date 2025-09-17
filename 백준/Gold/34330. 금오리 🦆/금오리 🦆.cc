#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    ll r, y;

    cin >> r >> y; // 연못 반지름이랑 뜰채 길이

    cin >> n >> m;
    vector<pair<pair<int, int>, int>> flower;
    vector<pair<pair<int, int>, int>> v(n);
    vector<bool> chk(n, 0);

    for(int i=0;i<n;i++){ // 연못 끝이랑 맞는지, 다른 연꽃이랑 닿는지
        cin >> a >> b >> c;
        v[i]={{(int)a, (int)b}, (int)c};
        flag=0;

        if ((r-c)<=0||(__int128)a*a+(__int128)b*b>=(__int128)(r-c)*(r-c) ){
            flower.push_back({{(int)a, (int)b}, (int)c});
            chk[i]=1;
            continue;
        }
        
        for(int j=0;j<flower.size();j++){
            if ( (__int128)(flower[j].first.first-a)*(flower[j].first.first-a)
               + (__int128)(flower[j].first.second-b)*(flower[j].first.second-b)
               <= (__int128)(c+flower[j].second)*(c+flower[j].second) ){
                flag=1;
                chk[i]=1;
                break;
            }
        }
        if(flag) flower.push_back({{(int)a, (int)b}, (int)c});
    }

    int tt=100;
    while(tt--){
        for(int i=0;i<n;i++){
            flag=0;
            if(!chk[i]){
                a=v[i].first.first;
                b=v[i].first.second;
                c=v[i].second;

                if ((r-c)<=0||(__int128)a*a +(__int128)b*b>=(__int128)(r-c)*(r-c)){
                    flower.push_back({{(int)a, (int)b}, (int)c});
                    chk[i]=1;
                    continue;
                }
        
                for(int j=0;j<flower.size();j++){
                    if ( (__int128)(flower[j].first.first-a)*(flower[j].first.first-a)
                       + (__int128)(flower[j].first.second-b)*(flower[j].first.second-b)
                       <= (__int128)(c+flower[j].second)*(c+flower[j].second)){
                        flag=1;
                        chk[i]=1;
                        break;
                    }
                }
                if(flag) flower.push_back({{(int)a, (int)b}, (int)c});
            }
        }
    }

    for(int i=0;i<m;i++){ // 오리 잡힘? 다 확인
        cin >> a >> b;

        if((r - y) <= 0 || (__int128)a*a + (__int128)b*b >= (__int128)(r-y)*(r-y)){
            ans++;
            continue;
        }
        for(int j=0;j<(int)flower.size();j++){
            if((__int128)(flower[j].first.first-a)*(flower[j].first.first-a)
               +(__int128)(flower[j].first.second-b)*(flower[j].first.second-b)
               <=(__int128)(y+flower[j].second)*(y+flower[j].second) ){
                ans++;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}
