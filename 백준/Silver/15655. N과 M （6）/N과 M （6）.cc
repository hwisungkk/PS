#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int ar[51][51]={0};
int visited[51]={0};
int k, m;
vector <int> v;
vector <int> pr;
vector <int> check(10);
void dfs(int n){
    if(n==m){
        for(auto a:pr)cout << a << ' ';
        cout << '\n';
        return;
    }
    for(int i=0;i<k;i++){
        if(check[i]==0){
            if(n==0 || (n!=0 && pr[n-1]<v[i])){
            check[i]=1;
            pr.push_back(v[i]);
            dfs(n+1);
            check[i]=0;
            pr.pop_back();
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n;
    long long a, b, c;

    int t;
    cin >> k >> m;
    for(int i=0;i<k;i++){
        cin >> c;
        v.push_back(c);
    }

    sort(v.begin(), v.end());

    dfs(0);

    
    
    
    return 0;
}