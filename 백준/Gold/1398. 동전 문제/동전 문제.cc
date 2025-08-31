#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;

    cin >> t;

    vector<ll> v;

    k=1;

    for(int i=0;i<=15;i++){
        v.push_back(k);
        k*=10;
    }

    k=25;
    for(int i=0;i<=6;i++){
        v.push_back(k);
        k*=100;
    }
    sort(v.rbegin(), v.rend());


    while(t-->0){
        ll ans=0;
        cin >> n;
        for(int i=0;i<v.size();i++){
            if(i%3==2){ // 25짜리들
                if(n>=3*v[i]){ // 75이상이면 일단 50을 빼는게 맞음
                    ans+=2;
                    n-=2*v[i];
                }

                if(n>=2*v[i]){
                    ll tmpn = n-2*v[i]; // 25*2 빼고 나머지 처리 방법
                    a=(tmpn%(v[i]*2/5))/(v[i]/25)+(tmpn/(v[i]*2/5))+2;

                    ll tmpn2 = n-v[i]; // 25 빼고 나머지 처리 방법
                    c=(tmpn2%(v[i]*2/5))/(v[i]/25)+(tmpn2/(v[i]*2/5))+1;

                    b=(n%(v[i]*2/5))/(v[i]/25)+(n/(v[i]*2/5)); //25 안빼고 처리 방법
                    ans+=min({a,b,c});

                    n%=(v[i]/25);

                }
                else if(n>=v[i]){
                    ll tmpn = n-v[i]; // 25 빼고 나머지 처리 방법
                    a=(tmpn%(v[i]*2/5))/(v[i]/25)+(tmpn/(v[i]*2/5))+1;

                    b=(n%(v[i]*2/5))/(v[i]/25)+(n/(v[i]*2/5)); //25 안빼고 처리 방법
                    ans+=min(a,b);

                    n%=(v[i]/25);
                }
            }
            else if(n>=v[i]){
                ans+=n/v[i];
                n%=v[i];
            }
        }
        cout << ans << '\n';
    }

    // 3000 에서 2500을 빼면 500, 5*100 but 3000을 1000*3으로 보면 더 빠름
    // 배수일 때만 그리디가 성립이니까

    return 0;
}
//반례 59 -> 25 + 10 + 10 + 10 + 1 + 1 + 1 + 1
