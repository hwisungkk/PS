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
#define mod 1000000007
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, k, t;
    int o_1, o_2;

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int k=0;k<n-i;k++){
            cout << ' ';
        }
        for(int j=0;j<i;j++){
            cout << '*';
        }
        cout << '\n';
    }
    for(int i=n-1;i>0;i--){
        for(int k=0;k<n-i;k++){
            cout << ' ';
        }
        for(int j=0;j<i;j++){
            cout << '*';
        }
        cout << '\n';
    }
    

    return 0;
}