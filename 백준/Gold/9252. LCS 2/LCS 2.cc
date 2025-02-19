#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int n, m, t;
    
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> v(s1.size()+1, vector<int>(s2.size()+1, 0));

    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                v[i][j]=v[i-1][j-1]+1;
            }
            else{
                v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
    }
    int mi = v[s1.size()][s2.size()];
    string ans_s="";
    a = s1.size();
    b = s2.size();
    while(v[a][b]!=0){
        if(v[a][b]==v[a][b-1])b--;
        else if(v[a-1][b]==v[a][b]) a--;
        else {
            ans_s += s1[a-1];
            a--;
            b--;
        }
    }
    if(mi==0)cout << mi;
    else {
        cout << mi << '\n';
        for(int i=ans_s.size()-1;i>=0;i--){
            cout << ans_s[i];
        }
    }

    return 0;
}