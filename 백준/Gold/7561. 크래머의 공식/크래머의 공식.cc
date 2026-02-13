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
const double PI = acos(-1.0);
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
    long long ans=0;

    cout<<fixed;
    cout.precision(3);

    cin >> t;
    while(t-->0){
        vector<double> a_1(3);
        vector<double> a_2(3);
        vector<double> a_3(3);
        vector<double> b_1(3);

        for(int i=0;i<3;i++){
            cin>>a_1[i]>>a_2[i]>>a_3[i]>>b_1[i];
        }

        double dt1, dt2, dt3, dta;
        dt1 = b_1[0] * (a_2[1] * a_3[2] - a_2[2] * a_3[1]) 
            - a_2[0] * (b_1[1] * a_3[2] - b_1[2] * a_3[1]) 
            + a_3[0] * (b_1[1] * a_2[2] - b_1[2] * a_2[1]);

        dt2 = a_1[0] * (b_1[1] * a_3[2] - b_1[2] * a_3[1]) 
            - b_1[0] * (a_1[1] * a_3[2] - a_1[2] * a_3[1]) 
            + a_3[0] * (a_1[1] * b_1[2] - a_1[2] * b_1[1]);

        dt3 = a_1[0] * (a_2[1] * b_1[2] - a_2[2] * b_1[1]) 
            - a_2[0] * (a_1[1] * b_1[2] - a_1[2] * b_1[1]) 
            + b_1[0] * (a_1[1] * a_2[2] - a_1[2] * a_2[1]);

        dta = a_1[0] * (a_2[1] * a_3[2] - a_2[2] * a_3[1]) 
            - a_2[0] * (a_1[1] * a_3[2] - a_1[2] * a_3[1]) 
            + a_3[0] * (a_1[1] * a_2[2] - a_1[2] * a_2[1]);


        cout.precision(0);
        cout << dt1 << ' ' << dt2 << ' ' << dt3 << ' ' << dta << '\n';
        double dd1=dt1/dta, dd2=dt2/dta, dd3=dt3/dta;
        if(dd1<0.0005 && -0.0005<dd1)dd1=0;
        if(dd2<0.0005 && -0.0005<dd2)dd2=0;
        if(dd3<0.0005 && -0.0005<dd3)dd3=0;

        cout.precision(3);
        if(dta<0.0005 && -0.0005<dta)cout<<"No unique solution\n";
        else{
            cout << "Unique solution: " << dd1 << ' ' << dd2 << ' ' << dd3 <<'\n';
        }
        if(t>0)cout<<'\n';
    }

    return 0;
}