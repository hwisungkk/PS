#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] ={-1,1,0,0};
int dy[4]={0,0,1,-1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    double d1, d2, d3;
    // d1 + d2 = a
    // d2 + d3 = c
    // d1 + d3 = b
    // d1 - d3 = a - c
    // d1 = (a + b - c) / 2
    // d2 = (a - b + c) / 2
    // d3 = (-a + b + c) / 2
    cout << fixed;
    cout.precision(1);
    if(((double)(a+b-c)/2)>0 && ((double)(a-b+c)/2)>0 && ((double)(b-a+c)/2)>0){
        cout << "1\n";
        cout << ((double)(a+b-c)/2) << ' ' << ((double)(a-b+c)/2) << ' ' << ((double)(b-a+c)/2);
    }
    else{
        cout << "-1\n";
    }
    return 0;
}