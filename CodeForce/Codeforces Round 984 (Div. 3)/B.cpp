/*https://codeforces.com/contest/2036/problem/B*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include<map>
#include <algorithm>
#include<math.h>
using namespace std;
int al=0;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c=0, total=0;
    char ch;
    long long count=0;
    int ma = -1000;
    int n, m, z=1;
    int dp[10000]={0};
    priority_queue <int, vector<int>> q1; //음수 저장
    priority_queue <int, vector<int>, greater<int>> q2; //양수 저장
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m >> z;
        count =0;
        map <int, int> ma;
        vector <int> v;
        for(int j=0;j<z;j++){
            cin >> a >> b;
            if(ma.find(a)!=ma.end()){
                ma.find(a)->second+=b;
            }
            else ma.insert({a, b});
        }
        for(pair <int,int> p : ma){
            v.push_back(p.second);
        }
        sort(v.begin(), v.end(), greater<>());
        c = v.size();
        for(int j=0;j<min(m,c);j++){
            count += v[j];
        }
        cout << count << '\n';
    }
    
    return 0;
}