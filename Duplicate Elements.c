// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
void main() {
    int array[] = {0,0,1,1,1,2,2,3,3,4};
        int c[10];
        int count =0;
        int n= (sizeof(array)/sizeof(array[0]));
   
    for (int i=0;i<n;i++){
         bool unique = 1;
        for(int j=i+1;j<n;j++){
            if(array[i]==array[j]){
                  unique = 0;
                  break;
            }
        }
    
        if(unique){
            c[count]=array[i];
            count = count+1;
        }
    }
    for ( int i=0;i<count;i++){
        for (int j=i+1;j<count;j++){
            if(c[i]>c[j]){
                int temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }
  printf("%d, nums=[",count);
    for(int i=0;i<count;i++){
        printf("%d",c[i]);
        if(i!=count-1){
            printf(",");
        }
    }
    printf("]");
}
