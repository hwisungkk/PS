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
vector <int> vc;
vector <int> pr;
vector <int> check(8);
int k, n;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    cin >> n;
    vector <int> v(n);
    vector <int> pre;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    pre.push_back(v[0]);
    for(int i=1;i<n;i++){
        int l = -1;
        int r = pre.size();
        int mid = (l+r)/2;
        while(l+1<r){
            mid = (l+r)/2;
            if(pre[mid] < v[i]) l = mid;
            else r = mid;
        }//lower bound
        //cout << l+1 << ' ';
        if(l+1<pre.size()){
            pre[l+1] = v[i];
        }
        else{
            pre.push_back(v[i]);
        }
    }//cout << '\n';
    cout << pre.size() << '\n';
    // for(int i=0;i<pre.size();i++){
    //     cout << pre[i] << ' ';
    // }
    return 0;
}