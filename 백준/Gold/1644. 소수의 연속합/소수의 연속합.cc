#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int n, m, k;
    int t;
    int mi = 1e9;
    string s;
    cin >> n;
    vector<int>prime;
    bool isprime[4000001] = {0};
    for(int i=2;i<=n;i++){
        if(isprime[i]==0)
        prime.push_back(i);
        for(int j=i;j<=n;j+=i){
            isprime[j]=1;
        }
    }
    int cnt = 0;
    int l = 0;
    int r = 0;
    int total = 2;
    while(r < prime.size() && l<=r){
        if(total<n){
            r++;
            total += prime[r];
        }
        else{
            total -=prime[l];
            l++;
        }
        if(total==n){
            cnt++;
        }
    }
    if(n==2)cnt=1;
    cout << cnt;
    return 0;
}
