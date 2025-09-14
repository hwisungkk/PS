#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1'000'000'007;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    cin >> t;
    vector<int> chk(1e7, 1);

    for(int i=2;i<1e7;i++){
        if(chk[i]==1){
            for(int j=i+i;j<1e7;j+=i){
                chk[j]=0;
            }
        }
    }
    vector<int> nu(1e7, 0);


    nu[1]=0;
    for(int i=1;i<=1e6;i++){
        nu[i]=nu[i-1]+chk[3*i+7];
    }
    while(t-->0){
        cin >> n;
        cout << nu[n] << '\n';
    }

    return 0;
}
