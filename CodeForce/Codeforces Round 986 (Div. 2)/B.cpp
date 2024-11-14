#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    long long n, m, k = -1;
    string s1, s2;
    int j;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        count=0;
        if(b==0){
            if(c<=a-3)
                cout << "-1\n";
            else if(a<=c){
                cout << a << '\n';
            }
            else{
                cout << a-1 << '\n';
            }
        }
        else{
            if(a-1<c)count=0;
            else{
                count = (a-1-c)/b+1;
            }
            cout << a - count << '\n';
        }
    }
    
    return 0;
}