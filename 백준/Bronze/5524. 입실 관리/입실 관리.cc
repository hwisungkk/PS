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
    long long a, b, c;

    int t;
    cin >> t;
    string s;
    getline(cin, s, '\n');
    for(int i=1;i<=t;i++){
        getline(cin, s, '\n');
        for(int j=0;j<s.size();j++){
            if(s[j]<97)s[j]+=32;
            cout<<s[j];
        }cout<<'\n';
    }

    return 0;
}