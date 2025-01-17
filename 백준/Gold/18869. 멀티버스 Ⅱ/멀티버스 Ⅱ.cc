#include <iostream>
#include <vector>
#include <string>
#include <tuple>
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
    long long a, b, c;
    int t;
    int n, m, k;
    int mi = 1e9;
    vector<vector<int>> fin;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        vector <int> v(m);
        vector <int> ar(m);
        vector <int> press(m);
        for(int j=0;j<m;j++){
            cin >> v[j];
            ar[j] = v[j];
        }
        sort(ar.begin(), ar.end());
        for(int j=0;j<m;j++){
            int l=-1;
            int r=m-1;
            int mid = (l+r)/2;
            while(l+1<r){
                mid = (l+r)/2;
                if(ar[mid]<v[j])l=mid;
                else r=mid;
            }
            press[j] = r;
        }
        fin.push_back(press);
    }
    int cnt=0;
    for(int i=0;i<fin.size()-1;i++){
        for(int j=i+1; j<fin.size();j++){
            if(fin[i]==fin[j])cnt++;
        }
    }
    cout << cnt;
    return 0;
}