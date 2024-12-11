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
vector <int> vc;
vector <int> pr;
vector <int> check(8);
int k, n;
void dfs(int v){
    if(v==k){
        for(auto q : pr)cout << q << ' ';
        cout << '\n';
        return;
    }
    vector <int> check2(10001, 0);
    for(int i=0;i<n;i++){
        if(check[i]==0 && check2[vc[i]]==0){
            check[i]=1;
            check2[vc[i]]=1;
            pr.push_back(vc[i]);
            dfs(v+1);
            pr.pop_back();
            check[i]=0;
        }
    }
    
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b;

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a;
        vc.push_back(a);
    }
    sort(vc.begin(), vc.end());
    dfs(0);
    return 0;
}