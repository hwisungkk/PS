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
    long long a, b, c;
 
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector <int> v(n);
        int ta=0;
        int tb=0;
        for(int i=0;i<n;i++){
            cin >> a;
            if(i%2==0){
                ta+=a;
            }
            else{
                tb+=a;
            }
        }
        if(tb%(n/2)==0 && ta%((n+1)/2)==0 && tb/(n/2) == ta/((n+1)/2)){
            cout<<"YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}