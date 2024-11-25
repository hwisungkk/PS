#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string>
#include <algorithm>
long long a, b, c, total = 0;
int n, m;
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long count = 0;
    int ma = -1;
    int ans = 100000000;
    string s1, s2;
    cin >> n;
    while(n--){
        cin >> a >> b;
        int check[10000]={0};
        queue <pair<int, string>> q;
        string s="";
        q.push({a, s});
        check[a]=1;
        while(!q.empty()){
            auto ca = q.front();
            c = ca.first;
            s = ca.second;

            //cout << "first : " << c << "second: " << s << '\n';
            q.pop();

            int D = c*2 % 10000;
            if(D==b){
                cout << s+'D'<<'\n';
                break;
            }
            if(!check[D]){
                check[D]=1;
                q.push({D, s+'D'});
            }

            int S = c-1; //S
            if(S==-1)S=9999;
            if(S==b){
                cout << s+'S'<<'\n';
                break;
            }
            if(!check[S]){
                check[S]=1;
                q.push({S, s+'S'});
            }
            
            int L; //L
            L = (c%1000)*10 + c/1000;
            if(L==b){
                cout << s+'L'<<'\n';
                break;
            }
            if(!check[L]){
                check[L]=1;
                q.push({L, s+'L'});
            }

            int R; //R
            R = c/10 + (c%10*1000);
            if(R==b){
                cout << s+'R'<<'\n';
                break;
            }
            if(!check[R]){
                check[R]=1;
                q.push({R, s+'R'});
            }
        }
    }
    return 0;
}