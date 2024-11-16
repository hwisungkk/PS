#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    int p = n;
    while(n--){
      long long total=0;
      cin >> m;
      vector <long long> v1(m);
      vector <long long> v2(m);
      for(int i=0;i<m;i++){
        cin>>v1[i];
      }
      for(int i=0;i<m;i++){
        cin>>v2[i];
      }
      sort(v1.begin(),v1.end());
      sort(v2.begin(),v2.end(), greater<int>());

      for(int i=0;i<m;i++){
        total += v1[i]*v2[i];
      }
      cout << "Case #" << p-n << ": " << total << '\n';
    }
}