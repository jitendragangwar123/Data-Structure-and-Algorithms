/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
 
struct S_Struct
{
      int top;
      int *arr;
      int mx;
};

struct S_Struct* createStack(int mx)
{
      struct S_Struct* S_obj = (struct S_Struct*)malloc(sizeof(struct S_Struct));
      S_obj -> mx = mx;
      S_obj -> top = -1;
      S_obj -> arr = (int*)malloc(S_obj -> mx*sizeof(int));
      return S_obj;
}
 
int isEmpty(struct S_Struct* S_obj)
{
      return (S_obj->top == -1);
} 
 
int isFull(struct S_Struct* S_obj)
{
      return (S_obj->top == S_obj->mx - 1);
}
 
void print(char fromTower, char toTower, int disk)
{
      printf("Move Disk %d from \'%c\' to \'%c\'\n", disk, fromTower, toTower);
}
 
void insert(struct S_Struct *S_obj, int item)
{
      if(isFull(S_obj))
      {
            return;
      }
      S_obj -> arr[++S_obj -> top] = item;
}
 
int delete(struct S_Struct* S_obj)
{
      if(isEmpty(S_obj))
      {
            return INT_MIN;
      }
      return S_obj -> arr[S_obj -> top--];
}
 
void shifting(struct S_Struct *tow_1, struct S_Struct *tow_2, char source, char dest)
{
      int tower1 = delete(tow_1);
      int tower2 = delete(tow_2);
      if(tower1 == INT_MIN)
      {
            insert(tow_1, tower2);
            print(dest, source, tower2);
      }
      else if(tower2 == INT_MIN)
      {
            insert(tow_2, tower1);
            print(source, dest, tower1);
      } 
      else if(tower1 > tower2)
      {
            insert(tow_1, tower1);
            insert(tow_1, tower2);
            print(dest, source, tower2);
      } 
      else
      {
            insert(tow_2, tower2);
            insert(tow_2, tower1);
            print(source, dest, tower1);
      }
}
 
void tower_of_hanoi(int limit, struct S_Struct *tow_1, struct S_Struct *tow_temp, struct S_Struct *tow_2)
{
      int count, shift;
      char dest = 'D', source = 'S', temp = 'A';
      if(limit % 2 == 0)
      {
            char x = dest;
            dest = temp;
            temp  = x;
      }
      shift = pow(2, limit) - 1;
      for(count = limit; count >= 1; count--)
      {
            insert(tow_1, count);
      } 
      for(count = 1; count <= shift; count++)
      {
            if(count%3 == 1)
            {
                  shifting(tow_1, tow_2, source, dest);
            } 
            else if(count%3 == 2)
            {
                  shifting(tow_1, tow_temp, source, temp);
            }
            else if(count%3 == 0)
            {
                  shifting(tow_temp, tow_2, temp, dest);
            }
      } 
}
 
int main()
{
      int limit;
      struct S_Struct *tow_1, *tow_2, *tow_temp;
      printf("\nEnter The Number of Disks:\t");
      scanf("%d", &limit);
      printf("\nSequence of Disk Moves:\n\n");
      tow_1 = createStack(limit);
      tow_temp = createStack(limit);
      tow_2 = createStack(limit);
      tower_of_hanoi(limit, tow_1, tow_temp, tow_2);
      printf("\n");
      return 0;
}
