#include<stdio.h>
int main(){
    int A, i, j, k;
    scanf("%d", &A);
    for(i=1;i<=A;i++){
        for(j=A-1;j>=i;j--){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}