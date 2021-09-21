#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <string.h>

#define N 4

void *myThread(int i){
  printf(">>Hello from my Thread %d \n",i);
  pthread_exit(NULL);

}

int main(){
  pthread_t = thread;
  for (int i = 0; i < N; i++){ 
   if(pthread_create(&thread, NULL, myThread,i)){
     printf(">>ERROR IN CREATING Thread #%d!\n",i);
     pthread_exit(NULL);
     return 1;
  } else {
      printf(">> Thread #%d created!\n");
   }
} 


