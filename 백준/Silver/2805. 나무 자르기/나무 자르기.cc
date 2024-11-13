#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int ma = -1;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(ma<v[i])ma=v[i];
    }
    int l = 0;
    int r = ma;
    int mid;
    while(l+1<r){
        mid = (l+r)/2;
        long long total=0;
        for(int i=0;i<n;i++){
            if(v[i]-mid>=0)
                total += (v[i]-mid);
        }
        if(total>=m) l = mid;
        else r = mid;
    }
    cout << l;

    return 0;
}