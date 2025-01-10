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
int v[101];
int n, m;
vector <int> index; //몇번째 들어갈지
vector <int> num; //무슨 숫자가 들어갈지
int num_check[6]={0};
int cnt=0;
void back(int k){
    if(k==index.size()){
        int score=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(v[i]<v[j])score++;
            }
        }
        if(score==m)cnt++;
        return;
    }
    for(int i=0;i<index.size();i++){
        if(v[index[i]]==0){
            int t;
            for(int j=0;j<num.size();j++){
                if(num_check[j]==0){
                    v[index[i]]=num[j];
                    t=j;
                    num_check[j]=1;
                    break;
                }
            }
            back(k+1);
            num_check[t]=0;
            v[index[i]]=0;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long k;
    long long a, b, c, d;

    string s;
    cin >> n >> m; //길이, 점수
    vector <int> check(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(v[i]==0)index.push_back(i);
        check[v[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(check[i]==0) num.push_back(i);
    }
    back(0);
    // for(int i=0;i<index.size();i++){
    //     cout << index[i] << '\n';
    // }cout << "---\n";
    // for(int i=0;i<num.size();i++){
    //     cout << num[i] << '\n';
    // }
    cout << cnt;
    
    return 0;
}