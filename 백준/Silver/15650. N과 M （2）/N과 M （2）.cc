#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int print[9]={0};
int check[9]={0};
void back(int m, int n, int k){
    for(int i=1;i<=m;i++){
        if(k>n){
            for(int p=1;p<=n;p++){
                cout << print[p] << ' ';
            }
            cout << '\n';
            return;
        }
        if(check[i]==0 && print[k-1]<i){
            print[k]=i;
            check[i]=1;
            back(m, n, k+1);
            check[i]=0;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    long long n, k = -1;
    int m;
    string s1, s2;
    cin >> m >> n;
    back(m, n, 1);
    
    return 0;
}