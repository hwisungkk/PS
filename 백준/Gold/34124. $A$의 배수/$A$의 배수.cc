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

    long long mod = 1'000'000'007;
    using P=pair<ll,ll>;

    long long a, b, c, d;
    long long ans = 0;

    // cin >> n;
    // vector<string> male(n);
    // vector<string> female(n);

    // for(int i=0;i<n;i++)cin>>male[i];
    // for(int i=0;i<n;i++)cin>>female[i];

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        //수 범위는 1~a까지, 지운 수가 b의 배수라면? 지운 수/b를 지울 수가 없음.
        //1~a에서 지운수가 b의 배수가 아니라면 언제든 지울 수 있음.

        //6 2
        //2를 지우면 1을 못지움.
        //4를 지우면 2를 못지움
        //6을 지우면 3을 못지움.
        //5는 언제든 가능.
        //1은?
        //3은?

        //킬각을 재려면 숫자가 2개만 남아있어야하고, x,y라고 할 때 x*b=y일 때 y를 지우면 킬각임.
        //그런데 굳이 상대가 이 킬각을 만들 필요가 있나? 지우려면 지울 수 있는 듯함.

        //n>=2
        //숫자가 2개면 위의 조건이 아닐 때 i승
        //숫자가 3개이상이면 킬각이 안잡히는데?
        //짝수면 I, 홀수면 O

        if(a==2)cout<<"O\n";
        else if(a%2==0)cout<<"I\n";
        else cout<<"O\n";
    }
    

    return 0;
}