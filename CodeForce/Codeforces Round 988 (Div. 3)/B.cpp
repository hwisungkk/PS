#include <iostream>
#include <vector>
#include <string>
#include <set>
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
        int a, b;
        vector<int> v(m);
        set<int> f;
        int check =0;
        for(int i=0;i<m;i++){
            cin >> v[i];
            if(check==1)continue;
            if((m-2) % v[i]==0){
                for(int k : f){
                    if(v[i]==k){
                        check=1;
                        a = v[i];
                        b = (m-2)/a;
                    }
                }
                f.insert((m-2) / v[i]);
            }
        }
        cout << a << " " << b << '\n';
    }
    
    return 0;
}
