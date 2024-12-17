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
    long long a, b, c;

    int t;
    cin >> t;
    if(t%3==0)cout<<'S';
    if(t%3==1)cout<<'U';
    if(t%3==2)cout<<'O';

    return 0;
}