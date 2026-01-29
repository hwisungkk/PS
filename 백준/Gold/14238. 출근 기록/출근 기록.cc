#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int chk[100][100][4];
int parent[1001];
int ran[1001];
int find(int u) {
   if (u == parent[u]) return u;
   return parent[u] = find(parent[u]);
}
void uni(int u, int v) {
   u = find(u);
   v = find(v);
   if (u == v) return;
   if (ran[u] > ran[v]) swap(u, v); 
   parent[u] = v;                                                                                                                                                                                                        
   if (ran[u] == ran[v]) ran[v]++;
}
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
    using P=pair<ll,ll>;

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    string s;
    cin >> s;

    a=0, b=0, c=0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='A')a++;
        if(s[i]=='B')b++;
        if(s[i]=='C')c++;
    }
    string anss="AA";

    //그리디하게 넣을 때 b나 c가 1개 남았으면 a와 다르지 않음
    //AA를 넣고 시작하는게 편할 듯

    for(int i=2;i<s.size()+2;i++){
        if(b>1 && b>a && anss[i-1]!='B'){
            anss.push_back('B');
            b--;
        }
        else if(c>1 && anss[i-1]!='C' && anss[i-2]!='C'){
            anss.push_back('C');
            c--;
        }
        else if(b>1 && anss[i-1]!='B'){
            anss.push_back('B');
            b--;
        }
        else if(c==1 && anss[i-1]!='C' && anss[i-2]!='C'){
            anss.push_back('C');
            c--;
        }
        else if(b==1 && anss[i-1]!='B'){
            anss.push_back('B');
            b--;
        }
        else if(a>=1){
            anss.push_back('A');
            a--;
        }
        else{
            flag=1;
            break;
        }
        //cout << "i: " << i << ' ' << anss << '\n';
    }

    if(flag)cout<<-1;
    else{
        for(int i=2;i<anss.size();i++){
            cout<<anss[i];
        }
    }

    return 0;
}
