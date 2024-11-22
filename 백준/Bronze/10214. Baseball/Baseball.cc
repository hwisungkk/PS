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
    
    cin >> n;
    while(n--){
        count=0;
        for(int i=0;i<9;i++){
            cin >> a >> b;
            if(a>b)count++;
            else if(a<b)count--;
        }
        cout<<"Yonsei\n";
    }
    return 0;
}