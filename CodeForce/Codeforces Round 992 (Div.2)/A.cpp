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
int ar[51][51]={0};
int visited[51]={0};
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
        int check=0;
        cin >> n >> k;
        vector <int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
 
        for(int i=0;i<n;i++){
            check=0;
            for(int j=0;j<n;j++){
                if(abs(v[i]-v[j])%k==0 && i!=j){
                    check=1;
                    break;
                }
            }
            if(check==0){
                cout << "YES\n" << i+1 << '\n';
                break;
            }
        }
        if(check==1){
            cout << "NO\n";
        }
    }
    
    
    return 0;
}