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
    
    int n, m, k;
    long long a, b, c, d;

    int t;
    cin >> t;
    k =0 ;
    for(int i=0;i<t;i++){
        cin >> a >> b;
        if(a==136)k+=1000;
        else if(a==142)k+=5000;
        else if(a==148)k+=10000;
        else if(a==154)k+=50000;
    }
    cout << k;
    
    
    return 0;
}