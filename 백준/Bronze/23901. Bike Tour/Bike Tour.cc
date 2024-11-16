#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, count=0;
    int m1, m2 = 2000;
    cin >> n;
    for(int i=1;i<=n;i++){
      count=0;
      cin >> m;
      vector<int>v (m);
      for(int j=0;j<m;j++){
        cin >> v[j];
      }
      for(int j=1;j<m-1;j++){
        if(v[j]>v[j-1] && v[j]>v[j+1]){
          count++;
        }
      }
      cout << "Case #" << i << ": " << count << '\n';
    }
}