#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    int n, m, t;
    
    cin >> t;
    a=0;
    while(t-->0){
        cin >> n;
        a++;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int check=0;

        for(int i=0;i<n-2;i++){
            for(int j=i+2;j<n;j++){
                for(int k=i+1;k<j;k++){
                    if(v[i]+v[j]==2*v[k]){
                        check=1;
                        break;
                    }
                }
            }
        }

        cout << "Case #" << a << ": ";
        if(check)cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}