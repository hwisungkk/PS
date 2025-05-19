#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    int n, m, t, k;
    bool flag=0; 

    string s;

    cin >> n >> m;
    vector<int> v(m);
    vector<vector<int>> record(m+1);
    for(int i=0;i<m;i++){
        cin >> v[i];
        record[v[i]].push_back(i);
    }

    vector<bool> check(m+1, 0); // 있는지 체크용
    vector<int> index(m+1, -1); //인덱스 저장용
    int ggot=0;
    int cnt=0;
    for(int i=0;i<m;i++){
        // for(int k=1;k<=m;k++){
        //     cout << check[k] << ' ';
        // }cout << '\n';
        if(check[v[i]]){
            index[v[i]]++;
            continue;
        }
        else if(check[v[i]]==0 && ggot < n){
            check[v[i]]=1;
            index[v[i]]++;
            ggot++;
        }
        else{
            int ma = -1;
            int change = 0;
            for(int j=1;j<=m;j++){
                if(check[j]==1){
                    if(record[j].size() <= index[j]+1){ //더이상 안쓰이면 빼버려
                        check[j]=0;
                        check[v[i]]=1;
                        index[v[i]]++;
                        ma=-1;
                        break;
                    }
                    else{
                        if(ma < record[j][index[j]+1]){ // 가장 먼 것을 찾아.
                            ma = record[j][index[j]+1];
                            change = j;
                        }
                    }
                }
            }
            cnt++;
            //cout << "!" << v[i] << " ma" << ma << '\n';
            if(ma==-1)continue; //이게 최선이니까
            else{
                check[change]=0;
                check[v[i]]=1;
                index[v[i]]++;
            }
        }
        //cout << "ggot: " << ggot << "i: " << v[i] << '\n';
    }
    cout << cnt;

    return 0;
}
