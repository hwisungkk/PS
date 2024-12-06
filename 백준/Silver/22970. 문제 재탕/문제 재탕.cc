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
int ar[102][102]={0};
int check[102]={0};
long long mi = 1e16;
int total=0;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    long long a, b, c;

    cin >> n;
    vector <int> v(n);
    int mi = 1;
    int total = 1;
    int ud = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=1;i<n;i++){
        if(ud==0 && v[i-1]<v[i]){
            total=2;
            ud = 1;
        }
        else if(ud==1 && v[i-1]<v[i]){
            total++;
            ud = 1;
        }
        else if(ud==1 && v[i-1]>v[i]){
            total++;
            ud = 0;
        }
        else if(ud==0 && v[i-1]>v[i]){
            total++;
            ud = 0;
        }
        else if(v[i-1]==v[i]){
            total=1;
            ud = 0;
        }
        if(mi<total)mi=total;
    }
    cout << mi;

    
    return 0;
}