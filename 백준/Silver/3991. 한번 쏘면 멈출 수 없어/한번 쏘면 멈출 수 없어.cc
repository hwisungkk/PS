#include <iostream>
#include <vector>
#include <string>
#include <string.h>
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
    long long n, m, t;
    char ch;
    string s;
    long long ans=0;
    bool flag=0;

    cin >> n >> m >> t;

    vector<int> v(t+1); // 개수, index
    for(int i=1;i<=t;i++){
        cin >> v[i];
    }
    vector<vector<int>> arr(n, vector<int>(m, 0));
    a=1;
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<m;j++){
                arr[i][j] = a;
                ans++;
                if(v[a] == ans){
                    a++;
                    ans=0;
                }
            }
        }
        else{
            for(int j=m-1;j>=0;j--){
                arr[i][j] = a;
                ans++;
                if(v[a] == ans){
                    a++;
                    ans=0;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j];
        }cout << '\n';
    }


    return 0;
}