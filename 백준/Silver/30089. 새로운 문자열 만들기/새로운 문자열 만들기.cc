#define ll long long
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        string s2="";
        k=0;
        cin >> s;
        for(int j=s.size()-1;j>=0;j--){
            s2+=s[j];
        }
        for(k=s.size()-1;k>=0;k--){
            if(s.substr(s.size()-1-k,k)==s2.substr(0, k))break;
        }
        //cout << "k : " << k << '\n';
        cout << s;
        for(int j=k+1;j<s.size();j++){
            cout << s2[j];
        }cout << '\n';
    }

    return 0;
}