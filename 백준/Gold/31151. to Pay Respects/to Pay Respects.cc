#define ll long long
#define i128 __int128_t
#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k = 0;
bool flag = 0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int chk[100][100][4];
int parent[1001];
int ran[1001];
int find(int u) {
   if (u == parent[u]) return u;
   return parent[u] = find(parent[u]);
}
void uni(int u, int v) {
   u = find(u);
   v = find(v);
   if (u == v) return;
   if (ran[u] > ran[v]) swap(u, v); 
   parent[u] = v;                                                                                                                                                                                                        
   if (ran[u] == ran[v]) ran[v]++;
}
ll gcd(ll x, ll y){
    if(x<y)swap(x,y);

    while(y!=0){
        ll tmp=y;
        y=x%y;
        x=tmp;
    }
    return x;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    using P=pair<ll,ll>;

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    cin >> a >> b >> c >> d >> n; //턴 횟수, 무기 뎀, 힐량, 독양, 독 횟수
    string s;
    cin >> s; //1이면 힐쓴거

    ans+= a*b;

    vector<int> v;

    for(int i=0;i<a;i++){
        if(s[i]=='1')v.push_back(i);
    }
    int idx=0;
    int r_p=0, p_p=0;
    vector<int> poison; //여기에 도달하면 독을 넣기
    int pidx=0;

    for(int i=0;i<a;i++){
        // i번째에 독을 쓰는 것은 독 총 데미지는 (a-i)*d가 들어가지만
        // 후에 k번째에 힐이 있다면 (a-k)*c의 힐이 됨.

        //k번째에 독을 맞춰쓰면 (a-k)*d만큼의 데미지를 줌.
        if(pidx<poison.size() && i==poison[pidx]){
            p_p++;
            pidx++;
            ans+= (p_p*d-r_p*c);
            continue; //여기서도 무조건 넘겨야함.
        }

        if(n>0){ // 독 포가 있을 때
            if(idx<v.size() && v[idx]==i){ //힐할땐
                idx++;
                p_p++;
                n--; 
            }
            else{
                if(idx<v.size() && (v[idx]-i)*d > (a-v[idx])*c){
                    p_p++;
                    n--;
                }
                else if(idx<v.size() && (v[idx]-i)*d <= (a-v[idx])*c){
                    poison.push_back(v[idx]);
                    idx++;
                    n--;
                    i--; //이 때는 다시 확인을 해야할 듯. 그냥 뒤에 있는 힐 타이밍을 지운거니까
                    continue;
                }
                else{
                    p_p++;
                    n--;
                }
            }
        }
        else{
            if(idx<v.size() && v[idx]==i){
                idx++;
                r_p++;
            }
        }
        //cout << "i: " << i << ' ' << "p_p: " << p_p << ' ' << "r_p: " << r_p << '\n';
        ans+= (p_p*d-r_p*c);
    }

    cout << ans;

    return 0;
}

//7 5 3 10 7
//1011111

//