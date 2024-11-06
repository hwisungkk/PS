/*https://codeforces.com/contest/2032/problem/B*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<math.h>
using namespace std;
int al=0;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, total=0;
    long long count=0;
    int ma = -1000;
    long long n, m, k=-1;
    int dp[101]={0};
    vector <vector <int>>kc;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(a!=1 && (b==1 || b == a)){
            cout<<"-1\n";
            continue;
        }
        if(a==1){
            cout << "1\n1\n";
        }
        else if(b<=(a/2)+1){
            cout << "3\n1 2 ";
            cout << 2*b-1<<"\n";
        }
        else if(b>(a/2)+1){
            cout << "3\n1 ";
            cout << 2*b-a + 1 << " ";
            cout << a << "\n";
        }
    }
    
    return 0;
}