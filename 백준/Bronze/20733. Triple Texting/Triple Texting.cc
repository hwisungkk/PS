#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int m;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    int ans = 100000000;
    long long n, k = -1;
    string s1, s2;
    
    cin >> s1;
    n = s1.size()/3;
    int check=0;
    for(int i=0;i<n;i++){
        if(s1[i]!=s1[i+n]){
            check=1;
        }
    }
    if(check==1){
        for(int i=0;i<n;i++){
            cout << s1[i+2*n];
        }
    }
    else{
        for(int i=0;i<n;i++){
            cout << s1[i];
        }
    }
    return 0;
}