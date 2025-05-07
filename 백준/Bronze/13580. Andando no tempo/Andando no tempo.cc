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
    int ans=0;
    bool flag=0;

    cin >> a >> b >> c;

    if(a==0||b==0||c==0)cout<<"S";
    else if(a==b||b==c||c==a)cout<<"S";
    else if(a+b==c||b+c==a||a+c==b)cout <<"S";
    else cout << "N";
    
    

    return 0;
}