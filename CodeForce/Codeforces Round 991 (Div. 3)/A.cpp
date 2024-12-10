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
        cin >> n >> m;
        int check = 0;
        int total = 0;
        string s;
        for(int i=0;i<n;i++){
            cin >> s;
            total += s.size();
 
            if(check==0 && total>m){
                check = 1;
                a = i;
            }
        }
        if(!check){
            a=n;
        }
        cout << a << '\n';
    }
    
    return 0;
}