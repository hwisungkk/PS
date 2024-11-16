#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, count=0;
    int m1, m2 = 2000;
    cin >> n;
    for(int i=1;i<=n;i++){
      vector <int> v(5);
      for(int j=0;j<5;j++){
        cin >> v[j];
      }
      sort(v.begin(),v.end());
      if(v[3]-v[1]>=4)cout<<"KIN\n";
      else cout << v[3]+v[1]+v[2] << '\n';
    }
}