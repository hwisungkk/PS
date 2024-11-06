#include <iostream>
#include <vector>
#include <string>
#include<math.h>
using namespace std;
int main() {
    int ar[60][60][60];
    int a, b, c;
    ar[0][0][0]=0;
    for(int i=0;i<=20;i++){
        for(int j=0;j<=20;j++){
            for(int k=0;k<=20;k++){
                if(i==0 || j ==0 || k ==0){
                    ar[i][j][k] = 1;
                }
                else if(i<j && j<k){
                    ar[i][j][k] = ar[i][j][k-1] + ar[i][j-1][k-1] - ar[i][j-1][k];
                }
                else{
                    ar[i][j][k] = ar[i-1][j][k] + ar[i-1][j-1][k] + ar[i-1][j][k-1] - ar[i-1][j-1][k-1];
                }
            }
        }
    }
    while(1){
        cin >> a >> b >> c;
        if(a==-1&&b==-1&&c==-1)break;
        if(a<=0 || b<=0 || c<=0){
            cout << "w(" << a << ", " << b << ", " << c << ") = " << "1" << '\n';
        }
        else if(a>20||b>20||c>20){
            cout << "w(" << a << ", " << b << ", " << c << ") = " << ar[20][20][20] << '\n';
        }
        else{
            cout << "w(" << a << ", " << b << ", " << c << ") = " << ar[a][b][c] << '\n';
        }
    }
    return 0;
}
