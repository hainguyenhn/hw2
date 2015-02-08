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

//
bool notVisited(int id, int* visited,int length);

//shortest job first
void shortestFirst(struct Process* myProcess, int arrayLength);

struct Report* reportProcessing(struct Process* sorted, int arrayLength);

int main()
{
  struct Process myProcessList[5];
  myProcessList[0].processId = 65;
  myProcessList[0].arrivalTime = 0.0;
  myProcessList[0].runTime = 8.2;
   myProcessList[1].processId = 66;
  myProcessList[1].arrivalTime = 0.4;
  myProcessList[1].runTime = 4.3;
   myProcessList[2].processId = 67;
  myProcessList[2].arrivalTime = 1.0;
  myProcessList[2].runTime = 1.9;
   myProcessList[3].processId = 68;
  myProcessList[3].arrivalTime = 0.5;
  myProcessList[3].runTime = 7.1;
   myProcessList[4].processId = 69;
  myProcessList[4].arrivalTime = 9;
  myProcessList[4].runTime = 3.7;


  //akeProcesses(myProcessList,5);
  myPrint(myProcessList,5);
  //printf("After sorted first come first serve\n");
  firstComefirstServe(myProcessList,5);
  //printf("After sorted shortest first \n");
  printf("hehe\n\n");
  shortestFirst(myProcessList,5);

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
    int i = 0;

    //copy array
    for (i = 0; i < arrayLength; i++){
        sorted[i] = myProcess[i];
    }
    int j = 0;

    //sort using bubble sort
    for(i = 0; i < arrayLength; i++){
        for (j = 0; j < arrayLength - 1 -i; j++){
            if (sorted[j].arrivalTime > sorted[j+1].arrivalTime){
                struct Process temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }
    myPrint(sorted,arrayLength);
    struct Report* myReport = reportProcessing(sorted,arrayLength);
        printReport(myReport,115);
}

void shortestFirst(struct Process* myProcess, int arrayLength){
     struct Process sortedArrival[arrayLength];
    int i = 0;
    //copy to new array.
    for (i = 0; i < arrayLength; i++){
        sortedArrival[i] = myProcess[i];
    }
    int j = 0;
    //sort array according to arrival time.
    for(i = 0; i < arrayLength; i++){
        for (j = 0; j < arrayLength - 1 -i; j++){
            if (sortedArrival[j].arrivalTime > sortedArrival[j+1].arrivalTime){
                struct Process temp = sortedArrival[j];
                sortedArrival[j] = sortedArrival[j+1];
                sortedArrival[j+1] = temp;
            }
        }
    }
        myPrint(sortedArrival,arrayLength);
    struct Process finalSorted[arrayLength];
    int counter = 0;
    int visited[] = {0,0,0,0,0};
    int currentTime = (int)sortedArrival[0].arrivalTime;
    //loop through until all  processes are completed
    while(counter < arrayLength){
            int temp = 0;
        //find the next shortest job
        for(i = 0; i < arrayLength; i++){
                if((notVisited(sortedArrival[i].processId,visited,arrayLength)) && (sortedArrival[i].arrivalTime < currentTime)){
                    if(sortedArrival[i].runTime < sortedArrival[temp].runTime){
                        temp = i;
                        printf("hehe %d\n", i);
                   }
                }
            }

           //add to visited
           visited[counter++] = sortedArrival[temp].processId;
           currentTime += (int)ceil(sortedArrival[temp].runTime);
        }

        struct Process sorted[arrayLength];
        for(i = 0; i < arrayLength; i++){

            for(j = 0; j < arrayLength; j++){
                if(sortedArrival[j].processId == visited[i]){
                    sorted[i] = sortedArrival[j];
                }
            }
        }

        for(i = 0; i < arrayLength; i++){
                printf("%c -", visited[i]);

        }

        struct Report* myReport = reportProcessing(sorted,arrayLength);
        printReport(myReport,115);
    }

bool notVisited(int id, int* visited,int length){
    bool result = true;
    int i;
    for(i = 0; i < length; i++){
        if(visited[i] == id){
            result = false;
        }
    }
    return result;
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
            printf("test %f",myReport->avgWaiting);
        }
        // if current time is less than next arrival time then set current time to arrival time.
        else{
            timeCounter = sorted[i].arrivalTime;
        }
        if(timeCounter > Time){
                break;
            }
        timeCounter += sorted[i].runTime;
       myReport->avgTurnAround += currentWaitTime + sorted[i].runTime;
       myReport->avgResponse += currentWaitTime + sorted[i].runTime + sorted[i].arrivalTime;

        int m = 0;
        m = (int)(timeCounter +1) - timeSlideCounter;
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
    printf("%c - ", (char)(myReport->timeSlice[i]));
    }
    printf("\nThroughput: %f", myReport->throughPut);
}

void myPrint(struct Process* myArray,int arrayLength){
    printf("%s%15s%15s%18s\n", "Process ID", "Arrival Time","Run Time", "Priority");
    int j = 0;
    for (j = 0; j < arrayLength; j++){
    printf("%c%20.2f%18.2f%15d\n", (char)(myArray[j].processId), myArray[j].arrivalTime, myArray[j].runTime, myArray[j].priority);
    }

}



