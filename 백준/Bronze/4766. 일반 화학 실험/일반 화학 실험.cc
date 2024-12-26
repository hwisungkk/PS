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
    double d;
    cin >> d;
    cout<<fixed;
    cout.precision(2);
    while(1){
        double d2;
        cin >> d2;
        if(d2==999.00)break;
        cout << d2-d <<'\n';
        swap(d,d2);
    }

    return 0;
}