#define ll long long
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
#include <map>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b){
    if (a.first==0)return false;
	else if (b.first==0)return true;
	else if (a.second==0 && b.second==0)return a.first < b.first;
	return a.second*b.first < a.first*b.second;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k=0;
    long long ans = 0;

    string s;

    cin >> n;
    vector<pair<int, int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end(), comp);

    t=0;
    for(int i=0;i<n;i++){
        t+= vp[i].first*t+vp[i].second;
        t%=40000;
    }
    cout << t;

    return 0;
}
