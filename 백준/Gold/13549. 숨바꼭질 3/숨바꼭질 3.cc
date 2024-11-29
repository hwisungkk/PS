#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long n, k = -1;
    int m;
    string s1, s2;
    cin >> n >> m;

    vector <int> v(1000000);
    queue <int> q;
    q.push(n);
    v[n]=1;
    while(!q.empty()){
        a = q.front();
        q.pop();
        for(int i=a*2;i<=100000;i*=2){
            if(v[i]!=0)break;
            v[i] = v[a];
            q.push(i);
        }
        if(v[a-1]==0 && a-1>=0){
            v[a-1] = v[a]+1;
            q.push(a-1);
        }
        if(v[a+1]==0 && a+1<=100000){
            v[a+1] = v[a]+1;
            q.push(a+1);
        }
    }
    cout << v[m]-1;
}