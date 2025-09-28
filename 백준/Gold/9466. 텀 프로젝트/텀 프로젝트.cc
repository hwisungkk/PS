#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int chk[100][100][100];
ll gcd(ll x, ll y){
    if(x<y)swap(x,y);

    while(y!=0){
        ll tmp=y;
        y=x%y;
        x=tmp;
    }
    return x;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;
    using P=pair<int,int>;

    long long a, b, c, d;
    long long ans = 0;
    string s;

    cin >> t;
    while(t-->0){
        cin >> n;
        ans=0;
        vector<int> v(n+1);
        vector<bool> chk(n+1, 0);
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }

        stack<int> st;
        for(int i=1;i<=n;i++){
            if(!chk[i]){
                st.push(i);
                chk[i]=1;
                a=i;
                while(1){
                    if(!chk[v[a]]){
                        chk[v[a]]=1;
                        st.push(v[a]);
                        a=v[a];
                    }
                    else{
                        b=v[a];
                        break;  
                    }
                }
                flag=0;
                int tmp=0;

                while(!st.empty()){
                    if(!flag){
                        tmp++;
                    }
                    if(st.top()==b)flag=1;
                    st.pop();
                }
                if(flag)ans+=tmp;
            }
        }
        cout << n-ans << '\n';
    }

    return 0;
}