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
int k, n;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    int t;
    string s1, s2;

    int ar[101][101]={0};
    int t1=0, t2=0;
    for(int i=0;i<4;i++){
        cin >> a;
        t1+=a;
    }
    for(int i=0;i<4;i++){
        cin >> a;
        t2+=a;
    }
    b = (t1>t2)?t1:t2;
    cout << b;
    return 0; 
}
