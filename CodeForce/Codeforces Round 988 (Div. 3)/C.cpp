#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int m;
vector <int> v(1000000);
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    long long n, k = -1;
    string s1, s2;
    int j;
        cin >> m;
        for(int i=0;i<m;i++){
            cin >> k;
            if(k<=4)cout << "-1";
            else{
                for(int i=k;i>=6;i--){
                    if(i%2==0)cout << i << " ";
                }
                cout << "2 4 5 1 3 ";
                for(int i=k;i>=6;i--){
                    if(i%2==1)cout << i << " ";
                }
            }
            cout << "\n";
        }
    
    return 0;
}