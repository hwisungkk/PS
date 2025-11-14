#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;
    using P=pair<ll,ll>;

    long long a, b, c, d;
    int n;
    long long ans = 0;

    cin >> n;
    vector<int> v(n+1);
    queue<int> q;
    ll tt=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        tt+=v[i];
        if(v[i]==1)q.push(i);
    }
    if(n<=1 || tt!=2*(n-1)){
        cout<<"BRAK";
        return 0;
    }
    vector<int> tmp;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i]-1;j++){
            tmp.push_back(i);
        }
    }
    for(int i=0;i<tmp.size();i++){
        v[tmp[i]]--;
        if(v[tmp[i]]==1) q.push(tmp[i]);
        cout << tmp[i] << ' ' << q.front() <<'\n';
        q.pop();
    }
    cout << q.front();
    q.pop();
    cout << ' ' << q.front();

    return 0;
}