#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int m;
vector <int> v(1000000);
int check(int n){
    if(n==m)return 0;
 
    if(n==v[n]){
        check(n+1);
    }
    else if(n==v[n+1]){
        if(v[n]==n+1){
            if(n+1==m)return 0;
            else check(n+2);
        }
        else{
            return -1;
        }
    }
 
    else
        return -1;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    long long n, k = -1;
    string s1, s2;
    int j;
    cin >> n;
    while(n--){
        cin >> m;
        count =0;
        int ma2=-1;
        vector <int> dp(m);
        for(int i=1;i<=m;i++){
            cin >> v[i];
        }
        j = check(1);
        if(j==-1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    
    return 0;
}
