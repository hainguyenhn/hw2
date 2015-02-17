#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Process{
    int processId;
    float arrivalTime;
    float runTime;
    int priority;
};

struct Report{
    int timeSlice[115];
    float avgTurnAround;
    float avgWaiting;
    float avgResponse;
    float throughPut;
};

//make processes
struct Process* makeProcesses(struct Process* myList,int num);

//print Process's Infor
void myPrint(struct Process* myProcess,int arrayLength);

//print report
void printReport(struct Report* myReport,int length);

//first come first serve
void firstComefirstServe(struct Process* myProcess, int arrayLenth);

//shortest job first
void shortestFirst(struct Process* myProcess, int arrayLength);

//sort array of process according to arrival time
void sort(struct Process* unsortList,struct Process* sortedList, int arrayLength);

//report Processing
struct Report* reportProcessing(struct Process* sorted, int arrayLength);

//highest priority first - non preemtive with aging
void highestPriorFirstNonPrewAging(struct Process* myProcess,int arrayLength);

//highest priority first - non preemtive without aging
void highestPriorFirstNonPre(struct Process* myProcess,int arrayLength);

//highest priority first -  preemtive without aging
void highestPriorFirstPre(struct Process* myProcess,int arrayLength);

//highest priority first -  preemtive with aging
void highestPriorFirstPrewAging(struct Process* myProcess,int arrayLength);

//return priority of a process.
int getPriority(struct Process* processList,int length,int id);

int main()
{
  struct Process myProcessList[25];
   myProcessList[0].processId = 65;
  myProcessList[0].arrivalTime = 0.12;
  myProcessList[0].runTime = 2.4;
  myProcessList[0].priority = 3;

  myProcessList[1].processId = 66;
  myProcessList[1].arrivalTime = 7.44;
  myProcessList[1].runTime = 2.8;
  myProcessList[1].priority = 2;

    myProcessList[2].processId = 67;
  myProcessList[2].arrivalTime = 25.53;
  myProcessList[2].runTime = 9.9;
  myProcessList[2].priority = 3;

    myProcessList[3].processId = 68;
  myProcessList[3].arrivalTime = 93.43;
  myProcessList[3].runTime = 1.8;
  myProcessList[3].priority = 1;

    myProcessList[4].processId = 69;
  myProcessList[4].arrivalTime = 3.49;
  myProcessList[4].runTime = 0.1;
  myProcessList[4].priority = 2;

    myProcessList[5].processId = 70;
  myProcessList[5].arrivalTime =  48.59;
  myProcessList[5].runTime = 2.8;
  myProcessList[5].priority = 2;

    myProcessList[6].processId = 71;
  myProcessList[6].arrivalTime = 9.15;
  myProcessList[6].runTime = 4.5;
  myProcessList[6].priority = 1;

    myProcessList[7].processId = 72;
  myProcessList[7].arrivalTime = 97.33;
  myProcessList[7].runTime = 6.7;
  myProcessList[7].priority = 3;

  myProcessList[8].processId = 73 ;
  myProcessList[8].arrivalTime = 56.33;
  myProcessList[8].runTime = 0.5;
  myProcessList[8].priority = 2;

    myProcessList[9].processId =74  ;
  myProcessList[9].arrivalTime =6.84 ;
  myProcessList[9].runTime = 3.0;
  myProcessList[9].priority = 3;

  myProcessList[10].processId = 75 ;
  myProcessList[10].arrivalTime = 7.47;
  myProcessList[10].runTime = 0.2;
  myProcessList[10].priority = 1;

    myProcessList[11].processId = 76 ;
  myProcessList[11].arrivalTime = 56.73;
  myProcessList[11].runTime = 5.2;
  myProcessList[11].priority = 2;

      myProcessList[12].processId = 77 ;
  myProcessList[12].arrivalTime = 72.06;
  myProcessList[12].runTime = 3.9;
  myProcessList[12].priority = 1;

      myProcessList[13].processId =78  ;
  myProcessList[13].arrivalTime = 2.65;
  myProcessList[13].runTime = 9.1;
  myProcessList[13].priority = 3;

      myProcessList[14].processId = 79 ;
  myProcessList[14].arrivalTime = 86.14;
  myProcessList[14].runTime = 5.5;
  myProcessList[14].priority = 2;

      myProcessList[15].processId = 80 ;
  myProcessList[15].arrivalTime = 62.82;
  myProcessList[15].runTime = 3.8;
  myProcessList[15].priority = 4;

      myProcessList[16].processId = 81 ;
  myProcessList[16].arrivalTime = 23.13 ;
  myProcessList[16].runTime = 5.3;
  myProcessList[16].priority = 2;

      myProcessList[17].processId = 82 ;
  myProcessList[17].arrivalTime = 89.74;
  myProcessList[17].runTime = 3.8;
  myProcessList[17].priority = 2;

      myProcessList[18].processId = 83  ;
  myProcessList[18].arrivalTime = 74.43;
  myProcessList[18].runTime = 3.6;
  myProcessList[18].priority = 2;

      myProcessList[19].processId = 84 ;
  myProcessList[19].arrivalTime = 21.91;
  myProcessList[19].runTime = 0.8;
  myProcessList[19].priority = 1;

      myProcessList[20].processId = 85 ;
  myProcessList[20].arrivalTime = 67.49;
  myProcessList[20].runTime = 4.4;
  myProcessList[20].priority =1 ;

      myProcessList[21].processId = 86;
  myProcessList[21].arrivalTime = 3.37;
  myProcessList[21].runTime = 6.7;
  myProcessList[21].priority = 1;

      myProcessList[22].processId = 87  ;
  myProcessList[22].arrivalTime = 74.28;
  myProcessList[22].runTime = 8.6;
  myProcessList[22].priority = 3;

      myProcessList[23].processId = 88  ;
  myProcessList[23].arrivalTime = 75.61;
  myProcessList[23].runTime = 4.4;
  myProcessList[23].priority = 2;

      myProcessList[24].processId = 89 ;
  myProcessList[24].arrivalTime = 14.30;
  myProcessList[24].runTime = 5.1;
  myProcessList[24].priority = 1;

  //akeProcesses(myProcessList,5);
 // myPrint(myProcessList,25);
  //firstComefirstServe(myProcessList,25);
//shortestFirst(myProcessList,25);
  //highestPriorFirstNonPrewAging(myProcessList,25);
  //highestPriorFirstNonPre(myProcessList,25);
  highestPriorFirstPre(myProcessList,25);
  printf("-----\n\n");
  highestPriorFirstPrewAging(myProcessList,25);
 return 0;
}

struct Process* makeProcesses(struct Process* myList,int num){
    srand(1);
    int i = 0;
    int j=65;
    for(i = 0;i < num; i++){
        myList[i].processId = j;
        j=j+1;
        myList[i].arrivalTime = (float)rand()/(float)(RAND_MAX/100);;
        myList[i].runTime = (float)rand()/(float)(RAND_MAX/10); + 0.1 ;
        myList[i].priority = rand()%4+1;
    }
    return myList;
}

void firstComefirstServe(struct Process* myProcess, int arrayLength){
    struct Process sorted[arrayLength];
    sort(myProcess,sorted,arrayLength);
    struct Report* myReport =reportProcessing(sorted,arrayLength);
        printf("First Come First Serve Analysis \n");
        printf("-------------------------------\n");
        printReport(myReport,115);
        printf("-------------------------------\n");
}

void shortestFirst(struct Process* myProcess, int arrayLength){
    int i = 0;
    int nextProcess;
    struct Process tempArray[arrayLength];
    //sort temp array to shortest arrival time.
    sort(myProcess,tempArray,arrayLength);
   // myPrint(tempArray,arrayLength);
    struct Process finalSorted[arrayLength];

    int counter = 0;
    float currentTime = tempArray[0].arrivalTime;
    //loop through until all  processes are completed
    while(counter < arrayLength){
             nextProcess = -99;
        //find the next shortest job up to current time.
        for(i = 0; i < arrayLength; i++){
                if((tempArray[i].processId != -99) && (tempArray[i].arrivalTime <= currentTime)){
                        //set temp to be the first qualify candidate.
                        if(nextProcess == -99){
                            nextProcess = i;
                        }
                //if current process has shorter run time than nextProcess then set nextProcess to be current.
                    if(tempArray[i].runTime < tempArray[nextProcess].runTime){
                        nextProcess = i;
                   }
                }
            }
            //add run time of process to timeslice
           currentTime += (int)ceilf(tempArray[nextProcess].runTime);
           //add process to final sorted array.
           finalSorted[counter++] = tempArray[nextProcess];
           //mark process as done.
           tempArray[nextProcess].processId = -99;
        }

        struct Report* myReport = reportProcessing(finalSorted,arrayLength);
        printf("\nShortest Job First Analysis \n");
        printf("-----------------------------\n");
        printReport(myReport,115);
        printf("-----------------------------\n");
    }

void highestPriorFirstNonPrewAging(struct Process* myProcess,int arrayLength){
    int i = 0;
    float tempAge= 0.0;
    int nextProcess;
    struct Process tempArray[arrayLength];
    //sort temp array to shortest arrival time.
    sort(myProcess,tempArray,arrayLength);
    myPrint(tempArray,arrayLength);
    float priorityQueue [4][4];
    memset(priorityQueue, 0.0, sizeof priorityQueue);
    struct Process finalSorted[arrayLength];
    float aging [arrayLength];
    memset(aging, 0, sizeof aging);
    int counter = 0;
    float currentTime = tempArray[0].arrivalTime;
    //loop through until all  processes are completed
    while(counter < arrayLength){
             nextProcess = -99;
               if(currentTime >99){
                    printf("end here %f",currentTime);
            break;
           }
        //find the next shortest job up to current time.
        for(i = 0; i < arrayLength; i++){
            if(tempArray[i].processId != -99){
                  if(tempArray[i].arrivalTime <= currentTime){
                        //set temp to be the first qualify candidate.
                        if(nextProcess == -99){
                            nextProcess = i;
                        }
                            aging[i]= currentTime- tempArray[i].arrivalTime - (aging[i]);
                         //   printf("Process %c priority: %d has wait time of %f\n",tempArray[i].processId,tempArray[i].priority,aging[i]);
                            while(aging[i] > 5){
                         //   printf("Process %c priority increase 1\n",tempArray[i].processId);
                            tempArray[i].priority--;
                            aging[i] -=5;
                            }
                         //    printf("NOW Process %c has priority: %d and wait time %f\n",tempArray[i].processId,tempArray[i].priority,aging[i]);
                            //if current process has higher than nextProcess then set nextProcess to be current.
                        if(tempArray[i].priority < tempArray[nextProcess].priority){
                                nextProcess = i;
                        }
                  }
            }
        }
     //   add turn around time
              priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][0] +=(currentTime - tempArray[nextProcess].arrivalTime);
         //   add wait time
              priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][1] +=(currentTime - tempArray[nextProcess].arrivalTime +
                        tempArray[nextProcess].runTime);
     //   add respond time
             priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][2] +=(currentTime - tempArray[nextProcess].arrivalTime +
                        tempArray[nextProcess].runTime);
         //    add throughput
       //  printf("before priority %d, number %f\n ", getPriority(myProcess,arrayLength,tempArray[nextProcess].processId),priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][3]);
        priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][3]++;
          //  printf("after priority %d, number %f \n", getPriority(myProcess,arrayLength,tempArray[nextProcess].processId),
                 //  priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][3]);
                  // priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][3]++;
        //   add to visited
     //   printf("Current time is %f\n", currentTime);
       // printf("Highest priority is process is %c - priority:%d\n", tempArray[nextProcess].processId,tempArray[nextProcess].priority);

           //add to visited
           currentTime = (int)ceilf(tempArray[nextProcess].runTime + currentTime);
           //add to final sort array.
           finalSorted[counter++] = tempArray[nextProcess];
           //mark process as done.
           printf("\n***process %c is done.\n",   tempArray[nextProcess].processId);
           tempArray[nextProcess].processId = -99;
    }

        for(i = 0; i < 4;i++){
            printf("Priority Queue %d:\n",i+1);
            printf("Turn around time: %f\n",priorityQueue[i][0]/=priorityQueue[i][3]);
            printf("Wait around time: %f\n",priorityQueue[i][1]/=priorityQueue[i][3]);
            printf("Respond around time: %f\n",priorityQueue[i][2]/=priorityQueue[i][3]);
            printf("Throughtput : %f\n",priorityQueue[i][3]);
            printf("-----------------\n");
        }

        struct Report* avgReport = reportProcessing(finalSorted,arrayLength);
        printf("\nHighest Priority First (Non Preemptive) w/ Aging Analysis \n");
        printf("-----------------------------\n");
        printReport(avgReport,115);
        printf("-----------------------------\n");
}

void highestPriorFirstNonPre(struct Process* myProcess,int arrayLength){
     int i = 0;
    float tempAge= 0.0;
    int nextProcess;
    struct Process tempArray[arrayLength];
    //sort temp array to shortest arrival time.
    sort(myProcess,tempArray,arrayLength);
    myPrint(tempArray,arrayLength);
    float priorityQueue [4][4];
    memset(priorityQueue, 0.0, sizeof priorityQueue);
    struct Process finalSorted[arrayLength];
    int counter = 0;
    float currentTime = tempArray[0].arrivalTime;
    //loop through until all  processes are completed
    while(counter < arrayLength){
             nextProcess = -99;
               if(currentTime >99){
            break;
           }
        //find the next shortest job up to current time.
        for(i = 0; i < arrayLength; i++){
            if(tempArray[i].processId != -99){
                  if(tempArray[i].arrivalTime <= currentTime){
                        //set temp to be the first qualify candidate.
                        if(nextProcess == -99){
                            nextProcess = i;
                        }
                         //    printf("NOW Process %c has priority: %d and wait time %f\n",tempArray[i].processId,tempArray[i].priority,aging[i]);
                            //if current process has higher than nextProcess then set nextProcess to be current.
                        if(tempArray[i].priority < tempArray[nextProcess].priority){
                                nextProcess = i;
                        }
                  }
            }
        }
     //   add turn around time
              priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][0] +=(currentTime - tempArray[nextProcess].arrivalTime);
         //   add wait time
              priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][1] +=(currentTime - tempArray[nextProcess].arrivalTime +
                        tempArray[nextProcess].runTime);
     //   add respond time
             priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][2] +=(currentTime - tempArray[nextProcess].arrivalTime +
                        tempArray[nextProcess].runTime);
         //    add throughput
       //  printf("before priority %d, number %f\n ", getPriority(myProcess,arrayLength,tempArray[nextProcess].processId),priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][3]);
            priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][3]++;
          //  printf("after priority %d, number %f \n", getPriority(myProcess,arrayLength,tempArray[nextProcess].processId),
                 //  priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][3]);
                  // priorityQueue[getPriority(myProcess,arrayLength,tempArray[nextProcess].processId)-1][3]++;
        //   add to visited

     //   printf("Current time is %f\n", currentTime);
       // printf("Highest priority is process is %c - priority:%d\n", tempArray[nextProcess].processId,tempArray[nextProcess].priority);

           //add to visited
           currentTime = (int)ceilf(tempArray[nextProcess].runTime + currentTime);
           //
           finalSorted[counter++] = tempArray[nextProcess];
           //mark process as done.
           printf("\n***process %c is done.\n",   tempArray[nextProcess].processId);
           tempArray[nextProcess].processId = -99;
    }

        for(i = 0; i < 4;i++){
            priorityQueue[i][0] /= priorityQueue[i][3];
            priorityQueue[i][1] /= priorityQueue[i][3];
            priorityQueue[i][2] /= priorityQueue[i][3];
            priorityQueue[i][3] /= currentTime;
        }

        for(i = 0; i < 4;i++){
            printf("Priority Queue %d:\n",i+1);
            printf("Turn around time: %f\n",priorityQueue[i][0]);
            printf("Wait around time: %f\n",priorityQueue[i][1]);
            printf("Respond around time: %f\n",priorityQueue[i][2]);
            printf("Throughtput : %f\n",priorityQueue[i][3]);
            printf("-----------------\n");
        }

        struct Report* avgReport =
        reportProcessing(finalSorted,arrayLength);
        printf("\nHighest Priority First (Non Preemptive) w/out Aging Analysis \n");
        printf("-----------------------------\n");
        printReport(avgReport,115);
        printf("-----------------------------\n");
} //end highest priority non preemptive without aging

void highestPriorFirstPre(struct Process* myProcess,int arrayLength){
    struct Process tempArray[arrayLength];
    //sort temp array to shortest arrival time.
    sort(myProcess,tempArray,arrayLength);
    myPrint(tempArray,arrayLength);
    //quantum array stores process of each quantum being worked on.
    int currentTime[1000] ;
    memset(currentTime, -1, sizeof currentTime);
    float startTime[arrayLength];
    memset(startTime, 0.0, sizeof startTime);
    float priorityQueue[4][4];
    memset(priorityQueue, 0.0, sizeof priorityQueue);
    int i,j;
    i = 0;
    tempArray[0].arrivalTime = floorf(tempArray[0].arrivalTime);
    tempArray[0].runTime = tempArray[0].runTime + tempArray[0].arrivalTime;
    float avgWaitTime = 0.0;
    float avgTurnAround = 0.0;
    float avgRespond = 0.0;
    float tempEndTime = 0.0;
    float tempWaitTime = 0.0;
    float tempTurnAround = 0.0;
    float tempRespond = 0.0;
    float avgThroughput = 0.0;
    int lastEmpty = 0;

    while((i< 100) || (lastEmpty == 0)){
        for(j = 0;j < arrayLength;j++){
            if((tempArray[j].arrivalTime <= i) && (tempArray[j].runTime > 0)){
                //set it for the first time.
                if(currentTime[i] == -1){
                currentTime[i] = j;
                }
                //if current has higher priority then set current = highest.
                if(tempArray[j].priority < tempArray[currentTime[i]].priority){
                    currentTime[i] = j;
                }
            }
        }
         if(currentTime[i] != -1){
                lastEmpty = 0;
                //  printf("%d Process %c Runtime Now:%f\n",i,tempArray[currentTime[i]].processId,tempArray[currentTime[i]].runTime);
                    tempArray[currentTime[i]].runTime--;
                    if(tempArray[currentTime[i]].runTime <= 0){
                        if(currentTime[i-1] == 95){
                            startTime[currentTime[i]] = tempArray[currentTime[i]].arrivalTime;
                        }
                        else{
                           startTime[currentTime[i]] =i;
                        }
                            tempEndTime = i+ tempArray[currentTime[i]].runTime+1;
                            tempWaitTime = tempEndTime - tempArray[currentTime[i]].arrivalTime -tempArray[currentTime[i]].runTime;
                            tempTurnAround = tempEndTime - tempArray[currentTime[i]].arrivalTime;
                            tempRespond = startTime[currentTime[i]] - tempArray[currentTime[i]].arrivalTime;
                            //add turn around.
                        priorityQueue[getPriority(myProcess,arrayLength,tempArray[currentTime[i]].processId)-1][0] += tempTurnAround;
                            //add waiting time.
                        priorityQueue[getPriority(myProcess,arrayLength,tempArray[currentTime[i]].processId)-1][1] += tempWaitTime;
                        //add respond time
                         priorityQueue[getPriority(myProcess,arrayLength,tempArray[currentTime[i]].processId)-1][2] +=tempRespond;
                         //add throughput.
                          priorityQueue[getPriority(myProcess,arrayLength,tempArray[currentTime[i]].processId)-1][3]++;
                    }
           // printf("Process %c Runtime After:%f\n\n",tempArray[currentTime[i]].processId,tempArray[currentTime[i]].runTime);
            }
            else{
                currentTime[i] = 95;
                lastEmpty = 1;
            }
         i++;
    }
  /**  for(j = 0; j < 115;j++){
        printf("%d.%c \n", j,tempArray[currentTime[j]].processId);
    }
    **/
   for(j = 0; j < 4;j++){
            avgTurnAround += priorityQueue[j][0];
            priorityQueue[j][0] /= priorityQueue[j][3];
            avgWaitTime += priorityQueue[j][1];
            priorityQueue[j][1] /= priorityQueue[j][3];
            avgRespond += priorityQueue[j][2];
            priorityQueue[j][2] /= priorityQueue[j][3];
            avgThroughput += priorityQueue[j][3];
            priorityQueue[j][3] /=i ;
        }

        avgTurnAround /= avgThroughput;
        avgWaitTime /= avgThroughput;
        avgRespond /= avgThroughput;
        avgThroughput /= i;
           printf("Average Turn Around Time: %.2f\n", avgTurnAround);
            printf("Average Turn Waiting Time: %.2f\n", avgWaitTime);
            printf("Average Turn Response Time: %f\n", avgRespond);
            printf("Throughput: %f\n", avgThroughput);
        for(j = 0; j < 4;j++){
            printf("Priority Queue %d:\n",j+1);
            printf("Turn around time: %f\n",priorityQueue[j][0]);
            printf("Wait around time: %f\n",priorityQueue[j][1]);
            printf("Respond around time: %f\n",priorityQueue[j][2]);
            printf("Throughtput : %f\n",priorityQueue[j][3]);
            printf("-----------------\n");
        }
}

void highestPriorFirstPrewAging(struct Process* myProcess,int arrayLength){
struct Process tempArray[arrayLength];
    //sort temp array to shortest arrival time.
    sort(myProcess,tempArray,arrayLength);
    myPrint(tempArray,arrayLength);
    //quantum array stores process of each quantum being worked on.
    int currentTime[1000] ;
    memset(currentTime, -1, sizeof currentTime);
    float startTime[arrayLength];
    memset(startTime, 0.0, sizeof startTime);
    float priorityQueue[4][4];
    memset(priorityQueue, 0.0, sizeof priorityQueue);
    int i,j;
    i = 0;
    tempArray[0].arrivalTime = floorf(tempArray[0].arrivalTime);
    tempArray[0].runTime = tempArray[0].runTime + tempArray[0].arrivalTime;
    float avgWaitTime = 0.0;
    float avgTurnAround = 0.0;
    float avgRespond = 0.0;
    float tempEndTime = 0.0;
    float tempWaitTime = 0.0;
    float tempTurnAround = 0.0;
    float tempRespond = 0.0;
    float avgThroughput = 0.0;
    int lastEmpty = 0;
        float aging [arrayLength];
    memset(aging, 0, sizeof aging);


    while((i< 100) || (lastEmpty == 0)){
        for(j = 0;j < arrayLength;j++){
            if((tempArray[j].arrivalTime <= i) && (tempArray[j].runTime > 0)){

            aging[j]++;

                //set it for the first time.
                if(currentTime[i] == -1){
                currentTime[i] = j;
                }
                //if current has higher priority then set current = highest.
                if(tempArray[j].priority < tempArray[currentTime[i]].priority){
                        aging[currentTime[i]]--;
                    currentTime[i] = j;
                }
            }
        }
        for(j = 0; j < arrayLength;j++){
               if(aging[j]>4){
                tempArray[j].priority++;
                aging[j] = 0;
            }
        }
         if(currentTime[i] != -1){
                lastEmpty = 0;
                //  printf("%d Process %c Runtime Now:%f\n",i,tempArray[currentTime[i]].processId,tempArray[currentTime[i]].runTime);
                    tempArray[currentTime[i]].runTime--;
                    if(tempArray[currentTime[i]].runTime <= 0){
                        if(currentTime[i-1] == 95){
                            startTime[currentTime[i]] = tempArray[currentTime[i]].arrivalTime;
                        }
                        else{
                           startTime[currentTime[i]] =i;
                        }
                            tempEndTime = i+ tempArray[currentTime[i]].runTime+1;
                            tempWaitTime = tempEndTime - tempArray[currentTime[i]].arrivalTime -tempArray[currentTime[i]].runTime;
                            tempTurnAround = tempEndTime - tempArray[currentTime[i]].arrivalTime;
                            tempRespond = startTime[currentTime[i]] - tempArray[currentTime[i]].arrivalTime;
                            //add turn around.
                        priorityQueue[getPriority(myProcess,arrayLength,tempArray[currentTime[i]].processId)-1][0] += tempTurnAround;
                            //add waiting time.
                        priorityQueue[getPriority(myProcess,arrayLength,tempArray[currentTime[i]].processId)-1][1] += tempWaitTime;
                        //add respond time
                         priorityQueue[getPriority(myProcess,arrayLength,tempArray[currentTime[i]].processId)-1][2] +=tempRespond;
                         //add throughput.
                          priorityQueue[getPriority(myProcess,arrayLength,tempArray[currentTime[i]].processId)-1][3]++;
                    }
           // printf("Process %c Runtime After:%f\n\n",tempArray[currentTime[i]].processId,tempArray[currentTime[i]].runTime);
            }
            else{
                currentTime[i] = 95;
                lastEmpty = 1;
            }
         i++;
    }
   /** for(j = 0; j < 115;j++){
        printf("%d.%c \n", j,tempArray[currentTime[j]].processId);
    }
    **/
   for(j = 0; j < 4;j++){
            avgTurnAround += priorityQueue[j][0];
            priorityQueue[j][0] /= priorityQueue[j][3];
            avgWaitTime += priorityQueue[j][1];
            priorityQueue[j][1] /= priorityQueue[j][3];
            avgRespond += priorityQueue[j][2];
            priorityQueue[j][2] /= priorityQueue[j][3];
            avgThroughput += priorityQueue[j][3];
            priorityQueue[j][3] /=i ;
        }

         avgTurnAround /= avgThroughput;
        avgWaitTime /= avgThroughput;
        avgRespond /= avgThroughput;
        avgThroughput /= i;
            printf("Average Turn Around Time: %.2f\n", avgTurnAround);
            printf("Average Turn Waiting Time: %.2f\n", avgWaitTime);
            printf("Average Turn Response Time: %f\n", avgRespond);
            printf("Throughput: %f\n", avgThroughput);


        for(j = 0; j < 4;j++){
            printf("Priority Queue %d:\n",j+1);
            printf("Turn around time: %f\n",priorityQueue[j][0]);
            printf("Wait around time: %f\n",priorityQueue[j][1]);
            printf("Respond around time: %f\n",priorityQueue[j][2]);
            printf("Throughtput : %f\n",priorityQueue[j][3]);
            printf("-----------------\n");
        }
}

struct Report* reportProcessing(struct Process* sorted, int arrayLength){
    struct Report* myReport = malloc(sizeof(struct Report));
    myReport->avgWaiting =0.0;
    myReport->avgTurnAround = 0.0;
    myReport->avgResponse = 0.0;
    myReport->throughPut = 0.0;
    int Time = 99;
    float timeCounter = 0;
    timeCounter = sorted[0].arrivalTime;
    int timeSlideCounter = 0;
    int i = 0;
    for(i = 0; i < arrayLength; i++){
        float currentWaitTime = 0;
        //only add to wait time if current time quantum is greater than arrival time.
        if(timeCounter > sorted[i].arrivalTime){
            currentWaitTime = timeCounter - sorted[i].arrivalTime;

           myReport->avgWaiting += currentWaitTime;
        }
        // if current time is less than next arrival time then set current time to arrival time.
        else{
            timeCounter = sorted[i].arrivalTime;
        }
        if(timeCounter > Time){
                break;
            }
        timeCounter += ceilf(sorted[i].runTime);
       myReport->avgTurnAround += currentWaitTime + sorted[i].runTime;
       myReport->avgResponse += currentWaitTime;

        int m = 0;
        m = (int)timeCounter - timeSlideCounter;
        while( m > 0)
        {
           myReport->timeSlice[timeSlideCounter++] = sorted[i].processId;
            m--;
        }
    }
        myReport->avgResponse = (myReport->avgResponse/(i));
        myReport->avgWaiting = (myReport->avgWaiting/(i));
        myReport->avgTurnAround = (myReport->avgTurnAround/(i));
        myReport->throughPut = i/timeCounter;
        return myReport;
}


void printReport(struct Report* myReport,int length){
    printf("Average Turn Around Time: %.2f\n", myReport->avgTurnAround);
    printf("Average Turn Waiting Time: %.2f\n", myReport->avgWaiting);
    printf("Average Turn Response Time: %f\n", myReport->avgResponse);

    int i = 0;
    printf("Time Slide: \n");
    for(i = 0; i < length; i++){
        if(i % 5 == 0 && i != 0){
            printf("-");
        }
    printf("%c",(char)(myReport->timeSlice[i]));
    }
    printf("\nThroughput: %f\n", myReport->throughPut);
}

void myPrint(struct Process* myArray,int arrayLength){
    printf("%s%15s%15s%18s\n", "Process ID", "Arrival Time","Run Time", "Priority");
    int j = 0;
    for (j = 0; j < arrayLength; j++){
    printf("%c%20.2f%18.2f%15d\n", (char)(myArray[j].processId), myArray[j].arrivalTime, myArray[j].runTime, myArray[j].priority);
    }
}

void sort(struct Process* unsortList,struct Process* sortedList, int arrayLength){
     int i = 0;
    //copy to new array.
    for (i = 0; i < arrayLength; i++){
        sortedList[i] = unsortList[i];
    }
    int j = 0;
    //sort array according to arrival time.
    for(i = 0; i < arrayLength; i++){
        for (j = 0; j < arrayLength - 1 -i; j++){
            if (sortedList[j].arrivalTime > sortedList[j+1].arrivalTime){
                struct Process temp = sortedList[j];
                sortedList[j] = sortedList[j+1];
                sortedList[j+1] = temp;
            }
        }
    }
}

int getPriority(struct Process* processList,int length,int id){
    int i,result = 1000;
    for(i = 0;i < length;i++){
        if(processList[i].processId == id){
            result = processList[i].priority;
            break;
        }
    }
    return result;
}




