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
    long long n, m;
    int j, k;
    string s1, s2;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        vector <int> v(a);
        for(int i=0;i<a;i++){
            cin >> v[i];
        }
        vector <long long> pre(a+1);
        for(int i=0;i<a;i++){
            pre[i+1]=pre[i]+v[i];
        }
        vector <int> left(a+1);
        vector <int> right(a+1);
        for(int i=1, j=0;i<=b;i++){
            while(j<=a && pre[j]-pre[left[i-1]]<c){
                j++;
            }
            left[i]=j;
        }
        right[0]=a;
        for(int i=1, j=a;i<=b;i++){
            while(j>=0 && pre[right[i-1]]-pre[j]<c){
                j--;
            }
            right[i]=j;
        }
        long long ans=-1;
        for (int i = 0; i <= b; i++) {
            if (left[i] <= right[b - i]) {
                ans = max(ans, pre[right[b - i]] - pre[left[i]]);
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}