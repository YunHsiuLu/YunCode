#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a=10;
  int *a_pointer;
  a_pointer=&a;
  printf("a的地址: %p = %p\n",a_pointer,&a);
  printf("a的值: %d = %d = %d\n",a,*&a,*a_pointer);

  int *A=malloc(5*sizeof(int));
  //for(int i=0;i<5;i++) *(A+i)=i;
  for(int i=0;i<5;i++) A[i]=i;

  printf("A的地址: %p = %p\n",A,&A[0]);

  for(int i=0;i<5;i++) 
    printf("A[%d]值: %d = %d\n",i,A[i],*(A+i));

  int **B=malloc( 2 * sizeof(int *) );

  B[0]=A;
  B[1]=A;

  for(int i=0;i<2;i++)
    for(int j=0;j<5;j++)
      printf("B[%d][%d]值: %d\n",i,j,B[i][j]);
  

  return 0;
}
