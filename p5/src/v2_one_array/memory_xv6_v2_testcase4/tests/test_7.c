#include "types.h"
 #include "stat.h"
 #include "user.h"
 
 
 #define DDEBUG 1
 
 #ifdef DDEBUG
 # define DEBUG_PRINT(x) printf x
 #else
 # define DEBUG_PRINT(x) do {} while (0)
 #endif
 
 
 int
 main(int argc, char *argv[])
 {
        int numframes = 1000;
          char *args[1];
          args[0] = "ls";
         int error=-11;
         int* frames = malloc(numframes * sizeof(int));
         int* pids = malloc(numframes * sizeof(int));
         //cid = fork();
         //if(cid == 0)
         //{//Child Process
                 int cid=fork();
                 if(cid==0)
                 error = exec("ls", args);
                wait();
                 int flag = dump_physmem(frames, pids, numframes);
                 if(flag == 0 && error!=-10)
                 {
                         for (int i = 0; i < numframes; i++)
                                 //if(*(pids+i) > 0)
                                         printf(1,"Frames: %x PIDs: %d\n", *(frames+i), *(pids+i));
                 }
                 else// if(flag == -1)
                 {
                         printf(1,"error\n");
                 }
 
         exit();
 
 
 
 }

