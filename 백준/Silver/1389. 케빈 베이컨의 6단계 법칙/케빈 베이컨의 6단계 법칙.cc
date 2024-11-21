#include <iostream>
#include <vector>
#include <string>
#include<queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int m;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    int ans = 100000000;
    long long n, k = -1;
    string s1, s2;
    int j;
    cin >> n >> m;
    vector <int> v(n+1);
    int ar[102][102]={0};
    for(int i=0;i<m;i++){
        cin >> a >> b;
        ar[a][b] = 1;
        ar[b][a] = 1;
    }
    for(int i=1;i<=n;i++){
        vector <int> check(n+1, 0);
        queue <int> q;
        int count =0;
        q.push(i);
        check[i]=1;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(int j=1;j<=n;j++){
                if(!check[j] && ar[p][j]==1){
                    q.push(j);
                    check[j] = check[p]+1;
                    count += check[p];
                }
            }
        }
        v[i]=count;
    }
    int y;
    for(int i=1;i<=n;i++){
        if(ans > v[i]){
            ans = v[i];
            y=i;
        }
    }
    cout << y;
    
    
    return 0;
}