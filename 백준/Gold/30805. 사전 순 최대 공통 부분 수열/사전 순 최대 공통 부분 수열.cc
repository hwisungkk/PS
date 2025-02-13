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
int dx[6]={0, 0, 1, 1, -1, -1};
int dy[6]={1,-1, 0, -1, 0, 1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, t;
    int a, b, c;
    cin >> n;
    vector<int> v1(n);
    for(int i=0;i<n;i++){
        cin >> v1[i];
    }
    cin >> m;
    vector<int> v2(m);
    for(int i=0;i<m;i++){
        cin >> v2[i];
    }
    vector<int> ans;
    int l = 0;
    int r = 0;
    int save_l=0;
    int save_r=0;
    for(int i=100;i>=1;i--){
        while(l<n && v1[l]!=i){
            l++;
        }
        while(r<m && v2[r]!=i){
            r++;
        }
        if(l<n && r<m){
            save_l = l;
            save_r = r;
            ans.push_back(i);
            i++;
            l++;
            r++;
        }
        else{
            l = save_l;
            r = save_r;
        }
    }

    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << ' ';
    }


    return 0;
}