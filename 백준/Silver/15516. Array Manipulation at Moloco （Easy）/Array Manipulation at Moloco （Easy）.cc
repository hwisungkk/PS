#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long n, k = -1;
    int m;
    string s1, s2;
    int ar[3];
    int max_dp[3]={0};
    int min_dp[3]={0};
    char c1, c2, c3, c4;
    cin >> n;
    vector <long long> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0l;j<i;j++){
            if(v[j]<v[i])count++;
        }
        cout<<count<<'\n';
    }
    return 0;
}