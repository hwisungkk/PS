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

    long long mod = 998'244'353;
    using P=pair<ll,ll>;

    long long a, b, c, d;
    long long ans = 0;

    string s1, s2;
    cin >> s1 >> s2;
    bool flag2=0;

    string t1="", t2="";
    for(int i=0;i<s1.size();i++){
        if(flag && s1[i]!='a'&&s1[i]!='e'&&s1[i]!='i'&&s1[i]!='o'&&s1[i]!='u'){
            flag2=1;
            break;
        }
        t1+=s1[i];
        if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u'){
            flag=1;
        }
    }
    if(!flag2)t1="";
    flag=0;
    flag2=0;
    for(int i=0;i<s2.size();i++){
        if(flag && s2[i]!='a'&&s2[i]!='e'&&s2[i]!='i'&&s2[i]!='o'&&s2[i]!='u'){
            flag2=1;
            break;
        }
        t2+=s2[i];
        if(s2[i]=='a'||s2[i]=='e'||s2[i]=='i'||s2[i]=='o'||s2[i]=='u'){
            flag=1;
        }
    }
    if(!flag2)t2="";


    if(t1.size()>0 && t2.size()>0) cout << t1 << t2;
    else cout << "no such exercise";
        

    return 0;
}