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
int ar[51][51]={0};
int visited[51]={0};
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
        int check=0;
        cin >> n;
        if(n==1)cout<<"1\n";
        else{
            for(int i=1;i<=200000;i=i*2+2){
                check++;
                if(n<=i){
                    cout<<check<<'\n';
                    break;
                }
            }
        }
    }
    
    
    return 0;
}