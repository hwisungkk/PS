#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k;
    long long a, b, c;

    int t;
    cin >> t;
    vector <int> v(t);
    for(int i=0;i<t;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    c = t-1;
    b = t*t;
    if(v.size()>=2){
        while(b--){
        for(int i=0;i<=c-1;i++){
            int check=0;
            if(v[i]+1 == v[i+1]){
                for(int j=i+1;j<=c;j++){
                    if(v[j]!=v[i+1]){
                        swap(v[j], v[i+1]);
                        check=1;
                        break;
                    }
                    if(j==c && check==0){
                        swap(v[i], v[j]);
                        c--;
                        break;
                    }
                }
            }
        }
        }
    }
    for(int i=0;i<t;i++){
        cout << v[i] << ' ';
    }

    return 0;
}