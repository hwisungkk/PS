#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<stack>
#include<cstring>
#include<string>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m=0;
    int a, b, t;
    long long count =0;
    cin >> n >> m;
    vector <long long> v;
    vector <long long> nu;
    long long k;
    long long div[1000] = {0};
    v.push_back(0);
    for(int i=0;i<n;i++){
        cin >> k;
        v.push_back(k);
    }
    nu.push_back(0);
    for(int i=1;i<=n;i++){
        k = v[i] + nu[i-1];
        nu.push_back(k);
    }
    for(int i=0;i<=n;i++){
        div[nu[i]%m]++;
    }
    for(int i=0;i<m;i++){
        count += (div[i]*(div[i]-1))/2;
    }
    
    cout << count;
    return 0;
}