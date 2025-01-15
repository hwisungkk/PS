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
vector<int> v;
int check[21] = {0};
set <int> s;
int total=0;
int n, m;
void back(int k, int x){
    s.insert(total);
    for(int i=x;i<n;i++){
        if(check[i]==0){
            total += v[i];
            check[i]=1;
            back(k+1, i);
            check[i]=0;
            total-=v[i];
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long a, b, c, d;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        v.push_back(m);
    }
    back(0,0);

    int re=0;
    for(auto it:s){
        if(re!=it){
            cout << re;
            return 0;
        }
        re++;
    }
    cout << re;
    
    return 0;
}