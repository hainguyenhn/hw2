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

//check if process is already complete
bool notVisited(int id, int* visited,int length);

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
  myPrint(myProcessList,25);
  firstComefirstServe(myProcessList,25);
  shortestFirst(myProcessList,25);

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
    struct Report* myReport = reportProcessing(sorted,arrayLength);
        printf("First Come First Serve Analysis \n");
        printf("-------------------------------\n");
        printReport(myReport,115);
        printf("-------------------------------\n");
}

void shortestFirst(struct Process* myProcess, int arrayLength){
     struct Process tempArray[arrayLength];
    int i = 0;
    int nextProcess;
    //sort temp array to shortest arrival time.
    sort(myProcess,tempArray,arrayLength);
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
           //add to visited
           currentTime += (int)ceilf(tempArray[nextProcess].runTime);
           //
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

struct Report* reportProcessing(struct Process* sorted, int arrayLength){
    struct Report* myReport = malloc(sizeof(struct Report));
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
        myReport->throughPut = timeCounter/(i);
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




