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
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, k, t;
    int o_1, o_2;
    string s1, s2;
    long long l1, l2;

    cin >> n;
    vector<long long> dul;
    vector<long long> na;
    for(int i=0;i<n;i++){
        cin >> s1;
        l1 = int(s1[0]-48)*pow(10, 8) + int(s1[1]-48)*pow(10, 7) + int(s1[3]-48)*pow(10, 6) + int(s1[4]-48)*pow(10, 5)
        + int(s1[6]-48)*pow(10, 4) + int(s1[7]-48)*1000 + int(s1[9]-48)*100 + int(s1[10]-48)*10 + int(s1[11]-48);
        cin >> s1;
        l2 = int(s1[0]-48)*pow(10, 8) + int(s1[1]-48)*pow(10, 7) + int(s1[3]-48)*pow(10, 6) + int(s1[4]-48)*pow(10, 5)
        + int(s1[6]-48)*pow(10, 4) + int(s1[7]-48)*1000 + int(s1[9]-48)*100 + int(s1[10]-48)*10 + int(s1[11]-48);

        dul.push_back(l1);
        na.push_back(l2);
    }
    dul.push_back(1e16);
    na.push_back(1e16);
    sort(dul.begin(), dul.end());
    sort(na.begin(), na.end());
    int mx = -1;
    int l=0, r=0;
    while(1){
        if(l==n && r==n)break;
        if(dul[l]<na[r]){
            l++;
        }
        else{
            r++;
        }
        mx = max(mx, l-r);
    }
    
    cout << mx;

    return 0;
}