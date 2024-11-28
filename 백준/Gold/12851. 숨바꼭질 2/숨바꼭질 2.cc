#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int m;
vector <pair<int, int>> v(1000000);
vector <int> check(1000000);
queue <int> q;
void bfs(int n){
    while(!q.empty()){
        al = q.front();
        q.pop();
        if(v[al].second==0){
            if(v[al-1].first+1 == v[al].first){
                v[al].second += v[al-1].second;
            }
            if(v[al+1].first+1 == v[al].first){
                v[al].second += v[al+1].second;
            }
            if(al%2==0 && (v[al/2].first+1 == v[al].first)){
                v[al].second += v[al/2].second;
            }
        }
        if(!check[al] && (v[al-1].first==0)){
            v[al-1].first=v[al].first+1;
            if(al<=100000 && al>=1)
                q.push(al-1);
        }
        if(!check[al] && (v[al+1].first==0)){
            v[al+1].first=v[al].first+1;
            if(al<100000)
                q.push(al+1);
        }
        if(!check[al] && (v[al*2].first==0)){
            v[al*2].first=v[al].first+1;
            if(al<50001)
                q.push(al*2);
        }
        check[al]=1;
        //cout << al << '\n';
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    long long n, k = -1;
    string s1, s2;
    int j;
    cin >> n >> m;
    q.push(n);
    v[n-1].second=1;
    v[n+1].second=1;
    v[n*2].second=1;
    bfs(n);
    v[n].first=0;
    v[n].second=1;
    cout << v[m].first << '\n' << v[m].second;
    
    return 0;
}