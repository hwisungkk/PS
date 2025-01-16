#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long ans;
    long long cnt = 0;
    int n, m, t;
    cin >> n >> m;
    map<string, vector<string>> group;
    map<string, string> member;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        cin >> t;
        for(int j=0;j<t;j++){
            string s2;
            cin >> s2;
            group[s].push_back(s2);
            member[s2]=s;
        }
        sort(group[s].begin(),group[s].end());
    }
    for(int i=0;i<m;i++){
        string s3;
        cin >> s3;
        cin >> a;
        if(a==0){
            for(int j=0;j<group[s3].size();j++){
                cout << group[s3][j]<<'\n';
            }
        }
        else if(a==1){
            cout << member[s3]<<'\n';
        }
    }
    
    return 0;
}