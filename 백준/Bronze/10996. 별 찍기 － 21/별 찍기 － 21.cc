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

    for(int i=1;i<=2*n;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                if(j%2) cout << '*';
                else cout << ' ';
            }
        }
        else {
            for(int j=1;j<=n;j++){
                if(j%2==0) cout << '*';
                else cout << ' ';
            }
        }
        cout << '\n';
    }
    

    return 0;
}