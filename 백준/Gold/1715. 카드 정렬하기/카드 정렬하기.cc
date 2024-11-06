#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> q;
    int n, t;
    int a, b;
    int count = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        q.push(t);
    }
    while(q.size()!=1){
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        count += a + b;
        q.push(a+b);
    }
    cout << count;
    return 0;
}
//10 20 40