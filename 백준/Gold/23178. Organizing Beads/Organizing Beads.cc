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
    int n, m, t, k;
    bool flag=1; 

    string s;

    cin >> n;
    cin >> s;
    cin >> m;
    vector<bool> v(n, 0);
    set<int> ss;
    for(int i=0;i<n;i++){
        if(s[i]=='O'){
            v[i]=1;
            ss.insert(i+1); 
        }
    }
    for(int i=0;i<m;i++){
        cin >> a;
        if(v[a-1]==0){
            v[a-1]=1;
            ss.insert(a);
        }
        else{
            v[a-1]=0;
            ss.erase(a);
        }
        int sz = ss.size();
        cout << min(n+1-*ss.begin()-sz, *prev(ss.end())-sz) << '\n';
    }
    //왼쪽에서 오른쪽 끝. X가 몇 개인지
    //오른쪽에서 왼쪽 끝. X가 몇 개인지


    return 0;
}
