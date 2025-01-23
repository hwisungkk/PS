#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;
    int n, m, x, y;
    int mi = 1e9;
    vector<int>check(1000000, 0);
    vector<int>prime;
    for(int i=2;i<=1000000;i++){
        if(check[i]==0){
            check[i]=2;
            prime.push_back(i);
            for(int j=i*2;j<=1000000;j+=i){
                check[j]=1;
            }
        }
    }
    while(1){
        cin >> n;
        if(n==0)break;
        for(int i=0;i<prime.size();i++){
            if(check[prime[i]]==2 && check[n-prime[i]]==2){
                cout << n << " = " << prime[i] << " + " << n-prime[i] << '\n';
                break;
            }
        }
    }
    
    return 0;
}