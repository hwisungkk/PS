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
vector<long long> v;
int check[45] = {0};
vector<long long>sum1;
vector<long long>sum2;
long long total=0;
int n, m;
void back(int k, int x){ //절반 앞
    sum1.push_back(total);
    for(int i=x;i<(n/2);i++){
        if(check[i]==0){
            total += v[i];
            check[i]=1;
            back(k+1, i);
            check[i]=0;
            total-=v[i];
        }
    }
}
void back2(int k, int x){ //절반 뒤
    sum2.push_back(total);
    for(int i=x;i<n;i++){
        if(check[i]==0){
            total += v[i];
            check[i]=1;
            back2(k+1, i);
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
    long long ans;
    long long cnt = 0;
    cin >> n >> ans;
    for(int i=0;i<n;i++){
        cin >> m;
        v.push_back(m);
    }
    back(0,0);
    total=0;
    back2(0,n/2);
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    for(int i=0;i<sum1.size();i++){
        int l = 0;
        int r = sum2.size();
        int mid=0;;
        while(l+1<r){
            mid = (l+r)/2;
            if(ans-sum1[i]<0){
                r=0;
                break;
            }
            if(sum2[mid] <= ans-sum1[i]) l=mid;
            else r=mid;
        }
        cnt += r;
    }
    cout << cnt;

    
    return 0;
}