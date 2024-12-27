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
    while(t-->0){
        string s;
        string s2 = "";
        int check=0;
        cin >> s;
        for(int i=s.size()-1;i>0;i--){
            if(s[i-1]<s[i]){
                check=1;
                for(int j=0;j<i-1;j++){
                    cout << s[j];
                }
                for(int j=s.size()-1;j>=i;j--){
                    if(s[i-1]<s[j]){
                        cout << s[j];
                        s[j] = 'Z';
                        break;
                    }
                }
                for(int j=i-1;j<s.size();j++){
                    s2 += s[j];
                }
                sort(s2.begin(), s2.end());
                for(int j=0;j<s2.size()-1;j++){
                    cout << s2[j];
                }
                cout << '\n';
                break;
            }
        }
        if(!check)cout << s << '\n';
    }
    return 0;
}