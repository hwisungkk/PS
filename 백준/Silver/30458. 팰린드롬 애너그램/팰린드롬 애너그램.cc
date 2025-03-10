#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    cin >> n;
    string s;
    cin >> s;
    vector<int> check(26, 0);
    for(int i=0;i<s.size();i++){
        if(s.size()%2==1){
            if(i == s.size()/2) continue;
        }
        check[s[i]-'a']++;
    }
    int flag = 0;
    for(int i=0;i<26;i++){
        if(check[i]%2==1) flag = 1;
    }
    if(flag){
        cout << "No";
    }
    else cout << "Yes";
    
    return 0;
}