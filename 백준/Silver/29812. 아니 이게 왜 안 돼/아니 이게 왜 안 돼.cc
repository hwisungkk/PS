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
    string s;
    cin >> s;
    cin >> n >> m;
    int countH=0;
    int countY=0;
    int countU=0;
    int count2=0;
    int total=0;
    for(int i=0;i<t;i++){
        if(s[i]=='H'){
            countH++;
            if(count2==1){
                total+=n;
            }
            else if(count2>1){
                total += min((n+m), count2*n);
            }
            count2=0;
        }
        else if(s[i]=='Y'){
            countY++;
            if(count2==1){
                total+=n;
            }
            else if(count2>1){
                total += min((n+m), count2*n);
            }
            count2=0;
        }
        else if(s[i]=='U'){
            countU++;
            if(count2==1){
                total+=n;
            }
            else if(count2>1){
                total += min((n+m), count2*n);
            }
            count2=0;
        }
        else{
            count2++;
        }
    }
    if(count2==1){
        total+=n;
    }
    else if(count2>1){
        total += min((n+m), count2*n);
    }

    if(total==0)cout<<"Nalmeok"<<'\n';
    else cout << total << '\n';

    if(min({countH, countY, countU})==0)cout<<"I love HanYang University"<<'\n';
    else cout << min({countH, countY, countU});
    
    return 0;
}