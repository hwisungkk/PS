#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
vector<int> v;
int check[21]={0};
int n, m;
int cnt=0;
int total=0;
void back(int k, int x){
    if(total==m){
        cnt++;
    }
    for(int i=x;i<n;i++){
        if(check[i]==0){
            check[i]=1;
            total+=v[i];
            back(k+1, i);
            check[i]=0;
            total-=v[i];
        }
    }
}
//  
//
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;
    int mi = 1e9;
    string s;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> t;
        v.push_back(t);
    }
    back(0, 0);
    if (m==0)cnt--;
    cout << cnt;

    return 0;
}