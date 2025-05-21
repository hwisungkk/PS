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
    long long n, m, t, k;
    bool flag=0; 

    string s;
    getline(cin, s);
    a=0;
    for(int i=0;i<s.size();i++){
        if(a==0 && s[i]=='U')a++;
        if(a==1 && s[i]=='C')a++;
        if(a==2 && s[i]=='P')a++;
        if(a==3 && s[i]=='C')a++;
    }
    if(a==4)cout << "I love UCPC";
    else cout << "I hate UCPC";

    // n + m*x < t*x

    return 0;
}
