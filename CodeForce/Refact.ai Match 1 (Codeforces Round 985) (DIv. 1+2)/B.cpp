#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, total = 0;
    long long count = 0;
    int ma = -1000;
    long long n, m, k = -1;
    int dp[50][1000] = {0};
    string s1, s2;
    int count0;
    int count1;
    vector<int> v;
    char ch;
    cin >> n;
    int j;
    for(int i=0;i<n;i++){
        int check=0;
        count0=0;
        count1=0;
        cin >> m;
        for(int j=0;j<m;j++){
            cin >> ch;
            if(ch=='0'){
                count0++;
            }
            else{
                count1++;
            }
        }
        for(j=0;j<m-1;j++){
            cin >> ch;
            if(check==1)continue;
            if(count0 <= 0 || count1 <= 0){
                check = 1;
            }
            if(ch=='1'){
                count0--;
            }
            else{
                count1--;
            }
        }
        if(check==0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}