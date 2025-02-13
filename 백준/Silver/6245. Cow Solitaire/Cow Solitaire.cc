#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, t;
    cin >> t;
    vector<vector<int>> ar(t+2, vector<int>(t+2, 0));
    for(int i=1;i<=t;i++){
        for(int j=1;j<=t;j++){
            string s;
            cin >> s;
            if(s[0]<='9'){
                ar[i][j] = int(s[0]-48);
            }
             else if(s[0]=='A') ar[i][j] = 1;
            else if(s[0]=='T') ar[i][j] = 10;
            else if(s[0]=='J') ar[i][j] = 11;
            else if(s[0]=='Q') ar[i][j] = 12;
            else if(s[0]=='K') ar[i][j] = 13;
        }
    }

    for(int i=t;i>=1;i--){
        for(int j=1;j<=t;j++){
            ar[i][j] += max(ar[i+1][j], ar[i][j-1]);
        }
    }

    cout << ar[1][t];

    return 0;
}