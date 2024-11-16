#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, count=0;
    int m1, m2 = 2000;
    char ar[100][100];
    string s;
    cin >> n;

    while(n--){
      cin >> s;
      int t=0;
      k = sqrt(s.size());

      for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
          ar[i][j]=s[t];
          t++;
        }
      }

      for(int i=k-1;i>=0;i--){
        for(int j=0;j<k;j++){
          cout<<ar[j][i];
        }
      }
      cout << '\n';
    }
}