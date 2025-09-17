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
    vector<pair<pair<ll, ll>, ll>> flower;
    vector<pair<pair<ll, ll>, ll>> v(n);
    vector<bool> chk(n, 0);

    for(int i=0;i<n;i++){ // 연못 끝이랑 맞는지, 다른 연꽃이랑 닿는지
        cin >> a >> b >> c;
        v[i]={{a, b}, c};
        flag=0;

        ll d=a*a+b*b;
        if(r-c<=0||d>=(r-c)*(r-c)){
            flower.push_back({{a, b}, c});
            chk[i]=1;
            //cout << a << ' ' << b << ' ' << c << '\n';
            continue;
        }
        
        for(int j=0;j<flower.size();j++){
            d= (flower[j].first.first-a)*(flower[j].first.first-a)+(flower[j].first.second-b)*(flower[j].first.second-b);

            if(d<=(c+flower[j].second)*(c+flower[j].second)){
                flag=1;
                chk[i]=1;
                break;
            }
        }
        if(flag) flower.push_back({{a, b}, c});
    }
    int tt=100;
    while(tt--){
        for(int i=0;i<n;i++){
            flag=0;
            if(!chk[i]){
                a=v[i].first.first;
                b=v[i].first.second;
                c=v[i].second;
                d = a*a+b*b;
                if(d>=(r-c)*(r-c)){
                    flower.push_back({{a, b}, c});
                    chk[i]=1;
                    //cout << a << ' ' << b << ' ' << c << '\n';
                    continue;
                }
        
                for(int j=0;j<flower.size();j++){
                d = (flower[j].first.first-a)*(flower[j].first.first-a)+(flower[j].first.second-b)*(flower[j].first.second-b);

                if(d<=(c+flower[j].second)*(c+flower[j].second)){
                    flag=1;
                    chk[i]=1;
                    break;
                }
            }
            if(flag) flower.push_back({{a, b}, c});
            }
        }
    }

    for(int i=0;i<m;i++){ // 오리 잡힘? 다 확인
        cin >> a >> b;

        double d = a*a+b*b;
        if(r-y<=0||d>=(r-y)*(r-y)){
            ans++;
            continue;
        }
        for(int j=0;j<flower.size();j++){
            d = (flower[j].first.first-a)*(flower[j].first.first-a)+(flower[j].first.second-b)*(flower[j].first.second-b);

            if(d<=(y+flower[j].second)*(y+flower[j].second)){
                ans++;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}