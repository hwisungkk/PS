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

    a=0;
    int d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    vector <string> st(b);
    for(int i=0;i<b;i++){
        cin >> st[i];
        sort(st[i].begin(), st[i].end());
    }
    int p=1;
    for(int i=0;i<a;i++){
        if(s[i]=='#'){
            if(b==p){
                if(d/pow(c, b-p)==0){
                    s[i] = st[p-1][c-1];
                }else{
                s[i] = st[p-1][d/pow(c, b-p)-1];
                }
            }else{
            s[i] = st[p-1][d/pow(c, b-p)];
            d = d % (int)pow(c,b-p); 
            p++;
            }
        }
        cout << s[i];
    }

    
    return 0;
}