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
    
    long long n, m, k;
    long long a, b, c;
 
    int t;
    cin >> t;
 
    while(t--){
        int check=0;
        cin >> n >> k;
 
        if(n<42) a = pow(2,n-1); //2^40 > 1e12
        else a=pow(2,40); //41일 때부터 여기 들어감.
        vector <int> v(n);
        int left=0;
        int right=n-1;
        
        if(k>a && n<41)cout<<"-1\n";
        else{
            for(int i=1;i<=n;i++){
                if(n>40){
                    while(n-i>40){
                        v[left]=i;
                        left++;
                        i++;
                    }
                }
                a/=2;
                if(k>a){
                    k-=a;
                    v[right]=i;
                    right--;
                }
                else{
                    v[left]=i;
                    left++;
                }
            }
            for(int i=0;i<n;i++){
                cout<< v[i] << ' ';
            }cout<<'\n';
        }
    }
    
    
    return 0;
}