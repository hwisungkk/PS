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
        int count2 = 0;
        int count3 = 0;
        int check = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='2')count2++;
            if(s[i]=='3')count3++;
            total += s[i]-48;
        }
        for(int i=0;i<=count2;i++){
            if((total+i*2) % 9 ==0){
                check = 1;
                cout << "YES\n";
                break;
            }
            if((total+i*2) % 9 ==6 && count3>=2){
                check = 1;
                cout << "YES\n";
                break;
            }
            if((total+i*2) % 9 ==3 && count3>=1){
                check = 1;
                cout << "YES\n";
                break;
            }
        }
        if(!check){
            cout << "NO\n";
        }
 
 
    }
    
    return 0;
}