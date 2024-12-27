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

    int t = 0;
    cin >> t;
    b=0;
    while(t-->0){
        b++;
        c=0, m=0;
        long long count=0;
        string s;
        cin >> s >> a;
        n = s.length();
        vector <int> v(n,0);
        for(int i=0;i<s.size();i++){
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')c++;
            else c=0;
            v[i]=c;

            if(v[i]>=a){
                count+= (i-a-m+2)*(n-i);
                m = i-a+2;
            }
        }

        cout << "Case #" << b << ": " << count << '\n';
    }
    return 0;
}