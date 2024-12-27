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
    cin >> a >> b >> c;
    for(int i = a/b;i>=0;i--){
        if(b*i==a){
            cout << i << ' ' << 0;
            return 0;
        }
        else{
            if((a-(b*i))%c==0){
                cout << i << ' ' << (a-(b*i))/c;
                return 0;
            }
        }
    }
    cout << "Impossible";

    return 0;
}