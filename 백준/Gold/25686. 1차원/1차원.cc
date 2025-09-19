#define ll long long
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
vector<int> v;
vector<int> ansv;
void con(vector<int> v1){
    if(v1.size()<=2){
        for(int i=0;i<v1.size();i++){
            ansv.push_back(v1[i]);
        }
        return;
    }

    vector<int> v2;
    vector<int> v3;
    for(int i=0;i<v1.size();i++){
        if(i%2==0){
            v2.push_back(v1[i]);
        }
        else v3.push_back(v1[i]);
    }
    con(v2);
    con(v3);
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    long long a, b, c, d;
    long long ans = 0;

    cin >> n;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }

    con(v);

    string sp="";
    for(int i=0;i<n;i++){
        cout << sp << ansv[i];
        sp=" ";
    }

    return 0;
}