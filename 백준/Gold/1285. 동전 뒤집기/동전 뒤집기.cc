#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int n, m, t;
    
    cin >> n;
    string s;
    vector<int> coin(n,0);
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            if(s[j]=='H')coin[i] = coin[i]*2 + 1;//앞면은 1
            else coin[i] = coin[i]*2; //뒷면은 0
        }
    }
    int mi = 1e9;
    vector<int> check(n, 0);
    function <void(int, int)> back = [&](int k, int x){
        if(k==n/2+1)return;
        int total=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if((coin[j]>>i)&1) cnt++; //i번째가 1이면
            }
            total += min(cnt, n-cnt);
        }
        mi = min(total, mi);
        for(int i=x;i<n;i++){
            if(check[i]==0)
            coin[i] ^= (1<<n)-1;
            check[i]=1;
            back(k+1, i+1);
            check[i]=0;
            coin[i] ^= (1<<n)-1;
        }
    };
    back(0, 0);
    cout << mi;

    return 0;
}