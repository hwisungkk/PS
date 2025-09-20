#define ll long long
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    long long a, b, c, d;
    //long long ans = 0;

    string s;
    cin >> s;

    vector<vector<int>> pos(5);
    for(int i=0;i<s.size();i++){
        if(s[i]=='s')pos[0].push_back(i+1);
        else if(s[i]=='n')pos[1].push_back(i+1);
        else if(s[i]=='u')pos[2].push_back(i+1);
        else if(s[i]=='p')pos[3].push_back(i+1);
        else if(s[i]=='c')pos[4].push_back(i+1);
    }
    cin >> n;
    for(int x=0; x<n; x++){
        cin >> a >> b;

        int hi = 1e9;
        for(int j=0;j<5;j++){
            int L1=0, R1=pos[j].size();
            while(L1<R1){
                int mi=(L1+R1)>>1;
                if(pos[j][mi] >= a) R1=mi;
                else L1=mi+1;
            }
            int L2=0, R2=pos[j].size();
            while(L2<R2){
                int mi=(L2+R2)>>1;
                if(pos[j][mi] >= b+1) R2=mi;
                else L2=mi+1;
            }
            hi = min(hi, R2 - R1);
        }
        if(hi<=0){
            cout << 0 << '\n';
            continue;
        } //최대 찾고

        int l2=-1, r2=hi+1;
        while(l2+1<r2){
            int mid2=(l2+r2)>>1;
            if(mid2==0){ 
                l2=0;
                continue;
            }

            int idx=a-1;
            flag=0;

            for(int j=0;j<5;j++){
                int target=idx+1;
                if(target<a) target=a;

                int L=0, R =pos[j].size();
                while(L<R){
                    int M=(L+R)>>1;
                    if(pos[j][M]>=target) R=M;
                    else L=M+1;
                }
                if(R==pos[j].size()){ 
                    flag=1;
                    break; }

                int idx2=R+(mid2-1);
                if(idx2>=pos[j].size()){
                    flag = 1;
                    break;
                }
                int pp=pos[j][idx2];
                if(pp>b){
                    flag = 1;
                    break;
                }

                idx=pp;
            }

            if(flag) r2=mid2;
            else l2=mid2;
        }

        cout << l2 << '\n';
    }
    return 0;
}