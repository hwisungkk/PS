#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <array>
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
    long long block = 0;
    int n, m;

    cin >> n >> m;
    int ar[100001]={0};
    queue <int> q;

    q.push(n);

    while(!q.empty()){
        a = q.front();
        q.pop();
        //cout << q.size()<<'\n';
        if(a-1>=0 && ar[a-1]==0){
            q.push(a-1);
            ar[a-1]=ar[a]+1;
        }
        if(a+1<=100000 && ar[a+1]==0){
            q.push(a+1);
            ar[a+1]=ar[a]+1;
        }
        if(a*2<=100000 && ar[a*2]==0){
            q.push(a*2);
            ar[a*2]=ar[a]+1;
        }
    }
    ar[n]=0;
    cout << ar[m];

    return 0;
}