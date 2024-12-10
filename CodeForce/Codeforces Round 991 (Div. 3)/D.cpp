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
        string s;
        cin >> s;
        int total = 0;
        int check = 0;
        char tp;
        for(int i=1;i<s.size();i++){
            if(s[i-1]<s[i]-1){
                tp = s[i-1];
                s[i-1] = char(s[i]-1);
                s[i] = tp;
                i=max(i-2,0);
            }
        }
        cout << s << '\n';
 
 
    }
    
    return 0;
}