#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h>  
  
int main() 
{ 
    // ftok to generate unique key 
    key_t key = ftok("shmfile",65); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  
    // shmat to attach to shared memory 
    char* encodedString = (char*) shmat(shmid,(void*)0,0); 
  
    printf("Data read from memory: %s\n",encodedString); 
      
    //detach from shared memory  
    shmdt(encodedString); 
    
    // destroy the shared memory 
    shmctl(shmid,IPC_RMID,NULL); 
     
    return 0; 
} 