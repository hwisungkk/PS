#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
int rag(int n, int t);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m=0;
    int a, b, t=0;
    priority_queue <int, vector<int>, greater<>> pq;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        if(m==0){
            if(pq.size()==0){
                cout << "0\n";
            }
            else{
                t = pq.top();
                cout << t << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(m);
        }
    }
    return 0;
}