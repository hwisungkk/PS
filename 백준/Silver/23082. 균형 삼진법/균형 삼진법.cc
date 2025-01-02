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
int n;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, m;
    int t;

    long long num;
    cin >> num;
    string s = "";

    long long k=3;
    while(1){
        if(num%k==0) s+='0';
        else if(num%k==-k/3 || num%k == k*2/3){
            s+='T';
            num+=k/3;
        }
        else{
            s+='1';
            num-=k/3;
        }
        if(num==0)break;
        k*=3;
    }
    for(int i=s.size()-1;i>=0;i--)cout<<s[i];
    // vector <vector<int>>(n, vector<int>(3));
    // for(int i=0;i<n;i++){

    // }
    // cin >> a >> b >> c;
    return 0;
}
