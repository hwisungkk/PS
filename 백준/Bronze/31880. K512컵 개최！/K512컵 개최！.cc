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
    char ch;
    string s;
    long long ans=0;
    bool flag=0;

    cin >> n >> m;
    vector <int> v1(n);
    vector <int> v2(m);
    for(int i=0;i<n;i++){
        cin >> a;
        ans += a;
    }
    for(int i=0;i<m;i++){
        cin >>a;
        if(a==0)continue;
        ans*=a;
    }
    cout << ans;


    return 0;
}