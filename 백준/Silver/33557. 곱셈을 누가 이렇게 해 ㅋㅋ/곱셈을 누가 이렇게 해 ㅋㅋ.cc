#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    char ch;
    string s;
    long long ans=0;
    bool flag=0;

    cin >> t;
    while(t-->0){
        cin >> n >> m;
        if(n < m) swap(n, m); // n이 더 크게
        long long real = n*m;
        string s1 = to_string(real);
        string s2= "";
        string sn = to_string(n), sm = to_string(m);
        int i=0;
        while(sn.size()-i != sm.size()){
            s2+=sn[i];
            i++;
        }
        for(int j=0;j<sn.size()-i;j++){
            string tmp = to_string(int(sn[j+i]-'0') * int(sm[j]-'0'));
            s2+=tmp;
        }
        if(s1==s2)cout << 1 << '\n';
        else cout << 0 << '\n';
    }


    return 0;
}