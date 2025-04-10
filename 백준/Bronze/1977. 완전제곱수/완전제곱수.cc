#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    long long n, m, t;
    bool flag=1; 
    long long mod = 1000;
    
    cin >> n >> m;
    int cnt=0;
    int mi=0;
    for(int i=ceil(sqrt(n)); i<=sqrt(m);i++){
        cnt+=i*i;
        if(mi==0)mi=i*i;
    }
    if(cnt==0){
        cout << "-1";
    }
    else{
        cout << cnt << '\n';
        cout << mi;
    }
    return 0;
}