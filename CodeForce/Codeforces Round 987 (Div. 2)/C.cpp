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
    cin >> n;
    while(n--){
        cin >> m;
        if(m%2==0){
            for(int i=1;i<=m/2;i++){
                cout << i << " " << i<< " ";
            }
        }
        else if(m>=27){
            cout << 1 << " ";
            for(int i=3;i<=6;i++){
                cout << i << " " << i<< " ";
            }
            cout << "1 " << "2 ";
            for(int i=7;i<=13;i++){
                cout << i << " " << i<< " ";
            }
            cout << "1 " << "2 ";
            for(int i=14;i<=(m-1)/2;i++){
                cout << i << " " << i<< " ";
            }
        }
        else{
            cout<<"-1";
        }
        cout << '\n';
    }
    
    return 0;
}