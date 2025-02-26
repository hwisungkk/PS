#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int parent[500001];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);
    parent[b] = a;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    cin >> n >> m;

    for(int i=0;i<=500000;i++){
        parent[i]=i;
    }

    int ans=0;
    for(int i=1;i<=m;i++){
        cin >> a >> b;
        if(!ans && find(a)!=find(b)){
            uni(a,b);
        }
        else if(ans==0){
            ans = i;
        }
    }
    cout << ans;

    return 0;
}