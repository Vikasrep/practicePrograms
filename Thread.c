/******************************************************************************
* FILE: Assignment.c
* 
* AUTHOR: 
* LAST REVISED: 07/17/2020
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#define NUM_THREADS	4

char *messages[NUM_THREADS];


//Global array
 int numberOfValues[NUM_THREADS];
//pointer to the array
 int *ptr = &numberOfValues[NUM_THREADS];

struct thread_data
{
   int	thread_id;
   char *message;
   char indexOne;
   char indexTwo;
};

struct thread_data thread_data_array[NUM_THREADS];

void *threadsToSumNumbers(void *threadarg)
{
   int taskid, sum;
   char *hello_msg;
   static char indexOne;
   static char indexTwo;
   int i;
   int sumTotal = 0;
   struct thread_data *my_data;
   

   sleep(1);
   my_data = (struct thread_data *) threadarg;
   taskid = my_data->thread_id;
   //sum = my_data->sum;
   hello_msg = my_data->message;
   indexOne = my_data->indexOne;
   indexTwo = my_data->indexTwo;
  
   
   for (i = indexOne; i <= indexTwo; ++i) {
                sumTotal += i;
     }
   
   printf("%s = %d\n", hello_msg, sumTotal);
   numberOfValues[taskid] = sumTotal;
   
   pthread_exit(NULL);
   
  
}

int finalTotal(int *ptr){	
int sum= 0, i;
int arr [4];

    
     switch(*ptr){
       case 55: arr[0] = (int)ptr[0];
	      
       case 155: arr[1] = (int)ptr[1];
       
       case 255: arr[2] = (int)ptr[2];
      
       case 355: arr[3] = (int)ptr[3];
       
       default : printf("");
       break;
 }
  
printf("Thread 0: %d\n", ptr[0]);
sleep(1);
printf("Thread 1: %d\n", ptr[1]);
sleep(1);
printf("Thread 2: %d\n", ptr[2]);
sleep(1);
printf("Thread 3: %d\n", ptr[3]);


for(i=0;i < NUM_THREADS; i++ ){
	sum = sum + (arr[i]);
	//printf("Total: %d\n", sum);
}

sleep(1);
printf("Total: %d\n", sum);

system("pause") ;
return 0;
 

}

int main(int argc, char *argv[] )
{
pthread_t threads[NUM_THREADS];
int *taskids[NUM_THREADS];
int rc, t, sum;
void *status = 0;
int *array1;



messages[0] = "The sum from 1 to 10";
messages[1] = "The sum from 11 to 20";
messages[2] = "The sum from 21 to 30";
messages[3] = "The sum from 31 to 40";
static char indexOne[] = {1, 11, 21, 31};
static char indexTwo[] = {10, 20, 30, 40};

for(t=0;t<NUM_THREADS;t++) {
  sum = sum + t;
  thread_data_array[t].thread_id = t;
  thread_data_array[t].message = messages[t];
  thread_data_array[t].indexOne = indexOne[t];
  thread_data_array[t].indexTwo = indexTwo[t];
  //*ptr =(int) malloc(sizeof(int[4])); 
   
   
   //creating a threads  
  rc = pthread_create(&threads[t], NULL, threadsToSumNumbers, (void *) 
       &thread_data_array[t]);
 
 	// Joining the threads
  pthread_join(threads[t], status);
  if (rc) {
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
    }
  }
    
	sleep(1);
	finalTotal(numberOfValues)	;
	  
pthread_exit(NULL);

}
