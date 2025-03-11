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
    int n, m, t;
    char ch;
    cin >> n;

    //정렬하고 처음 2개는 (0,1), (0,2)임.
    //마찬가지로 마지막 뒤는 (n-1, n), (n-2, n)임.
    //최대 100, 받는 숫자는 4950
    //그런데 (1,2)은 적어도 앞에서 101개 안에는 존재하게 됨.
    //(1,2)을 알면 1, 2, 3을 알 수 있게 되고 그러면 연쇄적으로 알 수 있지 않나?
    vector<int> v(n*(n-1)/2);
    vector<int> remove(2000001, 0);
    vector<int> remove2(2000001);
    for(int i=0;i<n*(n-1)/2;i++){
        cin >> v[i];
        remove[v[i]+1000000]++;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n, 0);
    if(n==2){ //2개면 따로 처리해야함.
        
        cout << min(0, v[0]) << ' ' << max(0, v[0]); // 98퍼 반례임 음수가 들어올 수도 있네
        return 0;
    }
    bool flag = 0;
    for(int i=2;i<n;i++){
        // 각각이 (1,2)인 경우를 고려
        if((v[0]+v[1]-v[i])%2!=0){
            continue;
        }
        flag = 1;
        ans[0] = (v[0]+v[1]-v[i])/2;
        ans[1] = v[0] - ans[0];
        ans[2] = v[1] - ans[0];
        //3개까지 구해놓기
        int cnt = 2;
        copy(remove.begin(), remove.end(), remove2.begin()); //시간이 괜찮나
        if(ans[0]+ans[1]>1000000 || ans[1]+ans[2]>1000000 || ans[0]+ans[2]>1000000){
            flag=0;
            continue;
        }
        if(remove2[ans[0]+ans[1]+1000000]>0)remove2[ans[0]+ans[1]+1000000]--;
        else {
            flag=0;
            continue;
        }
        if(remove2[ans[0]+ans[2]+1000000]>0)remove2[ans[0]+ans[2]+1000000]--;
        else {
            flag =0;
            continue;
        }
        if(remove2[ans[1]+ans[2]+1000000]>0)remove2[ans[1]+ans[2]+1000000]--;
        else {
            flag=0;
            continue;
        }
        int point = 0;
        while(1){
            if(cnt==n-1)break;
            cnt++;
            while(remove2[v[point]+1000000]==0){
                point++;
            }
            ans[cnt] = v[point] - ans[0];
            for(int j=0;j<cnt;j++){
                if(ans[cnt]+ans[j]>1000000){
                    flag=0;
                    break;
                }
                if(remove2[ans[cnt]+ans[j]+1000000]>0){ //(0,1), (0,2), (1,2)를 지우면 다음은 무조건 (0,3)임.
                    remove2[ans[cnt]+ans[j]+1000000]--;
                }
                else{
                    flag =0;
                    break;
                }
            }
            if(!flag)break;
        }
        if(cnt==n-1)break;
    }
    if(!flag){
        cout << "Impossible\n";
    }
    else{
        sort(ans.begin(), ans.end());
        for(int i=0;i<n;i++){
            cout << ans[i] << ' ';
        }
    }
    
    

    return 0;
}