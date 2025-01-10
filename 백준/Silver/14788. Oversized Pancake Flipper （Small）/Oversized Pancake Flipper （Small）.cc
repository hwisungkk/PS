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

    string s;
    int t;
    cin >> t;
    int in=0;
    while(t-->0){
        int count = 0;
        in++;
        cin >> s;
        cin >> k;

        for(int i=0;i<=s.size()-k;i++){
            if(s[i]=='-'){
                for(int j=i;j<i+k;j++){
                    if(s[j]=='-')s[j]='+';
                    else s[j]='-';
                }
                count++;
            }
        }
        int ch=1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-')ch=0;
        }
        if(ch)
            cout << "Case #" << in << ": " << count << '\n';
        else cout << "Case #" << in << ": IMPOSSIBLE" << '\n';
    }
    
    return 0;
}