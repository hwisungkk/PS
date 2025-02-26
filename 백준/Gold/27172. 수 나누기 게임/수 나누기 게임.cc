#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    int chk=0;
    
    cin >> n;
    vector<int> v(n);
    vector<bool> check(1000001, 0); //나왔는지 체크용
    vector<int> minus(1000001, 0); // 점수 차감용
    vector<int> plus(1000001, 0); // 점수 증가용
    for(int i=0;i<n;i++){
        cin >> v[i];
        check[v[i]]=1;
    }

    for(int i=0;i<n;i++){
        for(int j=v[i];j<1000001;j+=v[i]){
            if(check[j]){
                minus[j]++;
                plus[v[i]]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << plus[v[i]]-minus[v[i]] << ' ';
    }
   


    return 0;
}