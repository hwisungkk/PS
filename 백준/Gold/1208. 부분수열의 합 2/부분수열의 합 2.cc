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
int check[45] = {0};
vector<int>sum1;
vector<int>sum2;
int total=0;
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
    int ans;
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
    sort(sum2.rbegin(), sum2.rend());

    int l=0;
    int r=0;
    while(l<sum1.size() && r<sum2.size()){
        long long l_count=1;
        long long r_count=1;
        if(sum1[l]+sum2[r] == ans){
            while(l<sum1.size()-1 && sum1[l]==sum1[l+1]){
                l++;
                l_count++;
            }
            while(r<sum2.size()-1 && sum2[r]==sum2[r+1]){
                r++;
                r_count++;
            }
            if(l==sum1.size()-1){
                r++;
                cnt += l_count*r_count;
            }
            else{
                l++;
                cnt += l_count*r_count;
            }
        }
        else if(sum1[l]+sum2[r] < ans){
            l++;
        }
        else{
            r++;
        }
    }

    if(ans==0)cnt--; //공집합 제거
    cout << cnt;

    
    return 0;
}