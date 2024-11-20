#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int m;
vector <int> v(1000000);
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    long long n, k = -1;
    string s1, s2;
    int j;
    cin >> n;
    while(n--){
        cin >> m;
        int count=0;
        vector<int> v(m);
        vector<int> ar(m+1);
        for(int i=0;i<m;i++){
            cin >> v[i];
            ar[v[i]]++;
        }
        for(int i=0;i<m+1;i++){
            count += ar[i]/2;
        }
        cout << count << '\n';
    }
    
    return 0;
}