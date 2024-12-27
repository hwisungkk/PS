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
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k;
    int a, b, c;

    int t = 0;
    cin >> a >> b;
    vector <vector<int>> train(a+1, vector<int>(22, 0));
    for(int i=0;i<b;i++){
        cin >> n;
        if(n==1){
            cin >> m >> k;
            train[m][k]=1;
        }
        else if(n==2){
            cin >> m >> k;
            train[m][k]=0;
        }
        else if(n==3){
            cin >> m;
            for(int j=20;j>=1;j--){
                train[m][j+1] = train[m][j];
            }train[m][1]=0;
            train[m][21]=0;
        }
        else if(n==4){
            cin >> m;
            for(int j=1;j<=20;j++){
                train[m][j-1] = train[m][j];
            }train[m][20]=0;
            train[m][0]=0;
        }
    }
    set <vector<int>> s;
    for(int i=1;i<=a;i++){
        s.insert(train[i]);
    }
    cout << s.size();
    return 0;
}