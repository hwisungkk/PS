#define ll long long
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1'000'000;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    cin >> t;

    while(t-->0){
        double d1,d2,d3,d4;
        cin>>d1>>d2>>d3>>d4;

        if(d2/d1>d4/(d3*d3*3.141592))cout<<"Whole pizza\n";
        else cout<<"Slice of pizza\n";
    }
    

    return 0;
}