#define ll long long
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
vector<vector<ll>> mat(2, vector<ll>(2));
vector<vector<ll>> vv(2, vector<ll>(1));
vector<vector<ll>> mul(vector<vector<ll>> v1, vector<vector<ll>> v2){
    int r = v1.size();
    int c = v1[0].size();
    int d = v2[0].size();
    vector<vector<ll>> out(r, vector<ll>(d, 0));
    for(int i=0;i<r;i++){
        for(int kk=0;kk<c;kk++){
            for(int j=0;j<d;j++){
                out[i][j] =(out[i][j]+v1[i][kk]*v2[kk][j])%100;
            }
        }
    }
    return out;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    long long a, b, c, d;
    long long ans = 0;

    cin >> a >> b;
    string s1, s2, s3;

    cin >> s1 >> s2 >> s3;

    n=stoi(s2);
    m=stoi(s1);
    k=stoi(s3);


    if(k==0){
        cout << setw(2) << setfill('0') << n << '\n';
        return 0;
    }
    if(k==1){
        cout << setw(2) << setfill('0') << m << '\n';
        return 0;
    }

    mat[0][0]=a;
    mat[0][1]=b;
    mat[1][0]=1;
    mat[1][1]=0;
    vv[0][0]=n;
    vv[1][0]=m;

    vector<vector<ll>> res = {{1,0},{0,1}};
    vector<vector<ll>> base = mat;
    long long p = k-1;
    while(p>0){
        if(p%2) res = mul(res, base);
        base = mul(base, base);
        p/=2;
    }

    vector<vector<ll>> out = mul(res, vv);

    cout << setw(2) << setfill('0') << out[0][0] % 100 << '\n';

    return 0;
}