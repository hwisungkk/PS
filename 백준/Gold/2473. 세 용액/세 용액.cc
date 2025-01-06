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
    long long mi = 1e16;
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int n;
    int t;
    cin >> n;
    vector<long long> v(n);
    long long m;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(v[0]>=0){ //용액이 다 양수면 이게 정답
        cout << v[0] << ' ' << v[1] << ' ' << v[2];
    }
    else if(v[n-1]<=0){ //용액이 다 음수면 이게 정답
        cout << v[n-3] << ' ' << v[n-2] << ' ' << v[n-1];
    }
    else{
        for(int j=0;j<n-2;j++){
            for(int k=j+1;k<n-1;k++){
                m = v[j]+v[k]; //2개만 더한거.
                long long rm = -1*m;
                int l = k+1;
                int r = n-1;
                while(l+1<r){
                    int mid = (l+r)>>1;
                    if(v[mid]<=rm){
                        l = mid;
                    }
                    else if(v[mid]>rm){
                        r = mid;
                    }
                }
                if(abs(m+v[l])<mi){
                    mi = abs(m+v[l]);
                    a = v[j], b = v[k];
                    c = v[l];
                }
                if(abs(m+v[r])<mi){
                    mi = abs(m+v[r]);
                    a = v[j], b = v[k];
                    c = v[r];
                }//-24 -6 -3 -2 61 98 100
            }
        }
        cout << a << ' ' << b << ' ' << c;
    }

    return 0;
}
