#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
vector <long long> v;
int bin(long long bl, long long br, int m){
    int count = 0;
    long long bc = (bl+br)/2;
    //cout << "bl: " << bl << "br: " << br << "bc: " << bc << '\n';
    if(bl>br){
        cout << br;
        return 0;
    }
    for(int i=0;i<v.size();i++){
        count += v[i]/bc;
    }
    if(count>=m){
        bl = bc+1;
        bin(bl, br, m);
    }
    else{
        br = bc-1;
        bin(bl, br, m);
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, t;
    long long b, max = -1;
    int ans = 0;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> k;
        v.push_back(k);
        if(max < k) max = k;
    }
    bin(1, max, m);
    return 0;
}