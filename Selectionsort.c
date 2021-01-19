#include<stdio.h>
int main(){
   int i, j, count, temp, num[25];

   printf("number of elements : ");
   scanf("%d",&count);

   printf("next unsorted array : ", count);
   for(i=0;i<count;i++)
      scanf("%d",&num[i]);
 
   for(i=0;i<count;i++){
      for(j=i+1;j<count;j++){
         if(num[i]>num[j]){
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
         }
      }
   }

   for(i=0;i<count;i++)
      printf(" %d",num[i]);

   return 0;
}