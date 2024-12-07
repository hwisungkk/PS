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
int ar[102][102]={0};
int check[102]={0};
long long mi = 1e16;
int total=0;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    long long a, b, c;

    cin >> k;
    a=0;
    while(k--){
        a++;
        int d;
        string s;
        cin >> d >> s;
        int total=0;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(total < i){
                count++;
                total++;
            }
            total+=s[i]-48;
            //cout << total << ' ';
        }
        cout << "Case #" << a << ": " << count << '\n'; 
    }

    
    return 0;
}