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

    string s;
    string sp="";
    while(getline(cin, s)){
        cout << sp;
        flag=0;
        vector<int> v;
        string tmps="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                v.push_back(stoi(tmps));
                tmps="";
            }
            else tmps+=s[i];
        }
        v.push_back(stoi(tmps));

        int sz=v.size();
        priority_queue<P> pq;
        for(int i=0;i<sz;i++){
            pq.push({v[i], i});
        }
        vector<vector<int>> ansv(sz, vector<int>(sz, 0));

        while(!pq.empty()){
            int top=pq.top().first;
            int idx=pq.top().second;
            pq.pop();

            if(top<0 || top>pq.size()){
                flag=1;
                break;
            }
            queue <P> sv;
            for(int x=0;x<top;x++){
                ansv[idx][pq.top().second]=1;
                ansv[pq.top().second][idx]=1;
                sv.push({pq.top().first-1, pq.top().second});
                pq.pop();
            }
            while(!sv.empty()){
                pq.push(sv.front());
                sv.pop();
            }

        }
        if(flag)cout<<"fail\n";
        else{
            for(int i=0;i<sz;i++){
                for(int j=0;j<sz;j++){
                    cout << ansv[i][j] << ' ';
                }cout<<'\n';
            }
        }
        sp="\n";
    }
    

    return 0;
}