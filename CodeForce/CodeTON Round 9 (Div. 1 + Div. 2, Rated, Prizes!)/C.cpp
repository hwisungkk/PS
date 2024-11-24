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
        cin >> a >> b;
        count=0;
        for(int i=1;i<=4*a && i<=b;i++){
            c = a^i;
            if(c!=0 && (a%c==0 || i%c==0)){
                count++;
            }
        }
        cout<<count << '\n';
    }
    
    return 0;
}