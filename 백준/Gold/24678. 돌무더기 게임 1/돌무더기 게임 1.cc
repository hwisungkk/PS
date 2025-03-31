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
    int n, m, t;
    char ch;
    string s;
    int ans=0;
    bool flag=0;

    long long aa, bb, cc;
    cin >> t;
    int cnt=0;
    while(t-->0){
        cnt=0;
        cin >> a >> b >> c;
        if(a%2==0)cnt++;
        if(b%2==0)cnt++;
        if(c%2==0)cnt++;

        if(cnt>=2)cout << "R\n";
        else cout << "B\n";

    }
    

    return 0;
}