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
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k;
    int a, b, c;

    int t = 1000;
    int total=0;
    for(int i=0;i<4;i++){
        cin >> a;
        t = min(t, a);
        total+=a;
    }
    total-=t;
    t=1000;
    for(int i=0;i<2;i++){
        cin >> a;
        total+=a;
        t=min(t,a);
    }
    total-=t;
    cout << total;

    return 0;
}