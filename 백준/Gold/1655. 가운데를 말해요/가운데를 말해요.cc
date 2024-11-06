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
    priority_queue <int> pq;
    priority_queue <int, vector<int>, greater<int>> pq2;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        if(pq.size() == pq2.size()){
            pq.push(m);
        }
        else{
            pq2.push(m);
        }
        
        if(!pq2.empty() && pq.top() > pq2.top()){
            a = pq.top();
            pq.pop();
            b = pq2.top();
            pq2.pop();
            pq2.push(a);
            pq.push(b);
        }
        cout << pq.top() << '\n';
    }
    return 0;
}