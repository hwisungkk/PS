#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<bool> check(number.size(), 0);
    
    int point=0;
    while(k>0){
        for(int i=1;i<=k;i++){
            if(point+k==number.size()){
                for(int j=point;j<number.size();j++){
                    check[j]=1;
                }
                k=0;
            }
            if(number[point] < number[point+i]){
                for(int j=point;j<point+i;j++){
                    check[j]=1;
                }
                point += i;
                k-=i;
                i=0;
            }
            if(i==k){
                point++;
                i=0;
            }
        }
    }
    
    for(int i=0;i<number.size();i++){
        if(check[i]==0)answer+=number[i];
    }
    return answer;
}