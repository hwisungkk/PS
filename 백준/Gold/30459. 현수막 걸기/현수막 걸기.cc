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
    int n, m;
    double t;
    char ch;
    
    cin >> n >> m >> t;
    vector<int> mal(n);
    vector<int> git(m);
    for(int i=0;i<n;i++){
        cin >> mal[i];
    }
    for(int i=0;i<m;i++){
        cin >> git[i];
    }
    sort(mal.begin(), mal.end());
    vector<int> mal2;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            mal2.push_back(mal[i]-mal[j]);
        }
    }
    sort(mal2.begin(), mal2.end());
    sort(git.begin(), git.end());
    double ans=0;
    int point=m-1;
    while((double)mal2[0]*git[point]/2>t){
        point--;
        if(point==-1){
            cout << "-1";
            return 0;
        }
    }
    for(int i=0;i<mal2.size();i++){
        if((double)mal2[i]*git[point]/2<=t){
            ans = max(ans, (double)mal2[i]*git[point]/2);
        }
        else{
            point--;
            i--;
        }
        if(point==-1)break;
    }
    cout<<fixed;
    cout.precision(1);
    cout << ans;
    return 0;
}