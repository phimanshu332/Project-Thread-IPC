#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *fun1();
void *fun2();
void *fun3();
int min,max;
int size=6;
int i;
int D[]={90,81,78,95,79,72,85};
int main()

{

pthread_t p,q,r;
pthread_create(&p,NULL,fun1,D);
pthread_create(&q,NULL,fun2,D);
pthread_create(&r,NULL,fun3,D);
pthread_join(p,NULL);
pthread_join(q,NULL);
pthread_join(r,NULL);
}


void * fun2(int a[7])
{
   int sum;
   float avg;

   sum = avg = 0;
   
   for(i = 0; i < size; i++) {
      sum = sum + D[i];
   }
   
   avg = (float)sum / size;
   
   printf("Average of array values is %.2f\n", avg);   
   
   return 0;
}
void *fun1(int a[7])
{


    max = D[0];
    for(i=1; i<size; i++)
    {
        if(D[i] > max)
        {
            max = D[i];
        }
     }
printf("The maximum value is:%d\n",max);
}
void *fun3(int a[7])
{
    min = D[0];

   
    for(int i=1; i<size; i++)
    {
        if(D[i] < min)
        {
            min = D[i];
        }
    }
printf("The min value is: %d\n",min);
    
}
