#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
string s;
int pellen(int l, int r){
    while(l<r){
        if(s[l]!=s[r]){
            return 2;
        }
        l++;
        r--;
    }
    return 1;
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, k, t;

    cin >> n;

    //애드 훅인듯. 짝수면 가능 홀수면 불가능
    if(n!=1 && n%2==1){
        cout << "-1";
    }
    else{
        cout << n << ' ';
        for(int i=1;i<n;i++){
            if(i%2==1){
                cout << n-i << ' ';
            }
            else cout << i << ' ';
        }
    }

    return 0;
}