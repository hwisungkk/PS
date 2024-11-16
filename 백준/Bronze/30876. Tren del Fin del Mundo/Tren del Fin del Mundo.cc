#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    int m1, m2 = 2000;
    cin >> n;
    while(n--){
      cin >> m >> k;
      if(m2>k){
        m2=k;
        m1 = m;
      }
    }
    cout << m1 << " " << m2;
}