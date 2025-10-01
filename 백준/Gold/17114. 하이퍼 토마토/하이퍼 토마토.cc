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
    //long long n, m, t, k = 0;
    long long ans = 0;
    vector<int> val(11, 0);
    vector<int> dst;
    int sz=1;

    for(int i=0;i<11;i++){
        cin>>val[i];
        dst.push_back(sz);
        sz*=val[i];
    }

    vector<int> vv(sz);
    vector<bool> chk(sz, 0);

    queue<int> qq;

    for(int i=0;i<sz;i++){
        cin>>vv[i];
        if(vv[i]!=0)chk[i]=1;
        if(vv[i]==1){
            qq.push(i);
        }
    }

    while(!qq.empty()){
        int tmp = qq.front();
        chk[tmp]=1;
        qq.pop();
        for(int i=0;i<11;i++){
            if(tmp-dst[i]>=0 && vv[tmp-dst[i]]==0){
                flag=0;
                for(int j=10;j>i;j--){
                    if(tmp/dst[j]!=(tmp-dst[i])/dst[j]){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    vv[tmp-dst[i]]=vv[tmp]+1;
                    qq.push(tmp-dst[i]);
                }

            }
            if(tmp+dst[i]<sz && vv[tmp+dst[i]]==0){
                flag=0;
                for(int j=10;j>i;j--){
                    if(tmp/dst[j]!=(tmp+dst[i])/dst[j]){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    vv[tmp+dst[i]]=vv[tmp]+1;
                    qq.push(tmp+dst[i]);
                }
            }
        }
        ans = max((int)ans, vv[tmp]);
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<6;j++){
    //         cout << vv[i*6+j] << ' ';
    //     }cout<<'\n';
    // }
    // cout << "----\n";
    }
    for(int i=0;i<sz;i++){
        if(chk[i]==0){
            ans=0;
            break;
        }
    }


    cout << ans-1;

    return 0;
}