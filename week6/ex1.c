#include <stdio.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct{
  int id;
  int arrival_time;
  int burst_time;

  int ct, tat, wt;
} Process;


void swap(Process *p1, Process *p2){
  Process tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

void sort(Process *array, int size){
  for(int i = 0; i < size - 1; i++){
    for(int j = 0; j < size - 1 - i; j++){
      if(array[j].arrival_time > array[j+1].arrival_time){
        swap(&array[j], &array[j+1]);
      }
    }
  }
}

void read_proc(Process proc[], int size){
  for(int i = 0; i < size; i++){
    scanf("%d %d", &(proc[i].arrival_time), &(proc[i].burst_time)); 
  }
}

void calc_ct(Process *proc, int size){
  int time = 0;
  for(int i = 0; i < size; i++){
    if(time >= proc[i].arrival_time){
      time += proc[i].burst_time;
    } else {
      time = proc[i].arrival_time + proc[i].burst_time;
    }
    proc[i].ct = time;
  }
}

void calc_tat(Process *proc, int size){
  for(int i = 0; i < size ; i++)
    proc[i].tat = proc[i].burst_time + proc[i].wt;
}

void calc_wt(Process *proc, int size){
  proc[0].wt = 0;
  for(int i = 1; i <size; i++){
    proc[i].wt = MAX(0, proc[i-1].ct - proc[i].arrival_time);
  }
}

double average_tat(Process *proc, int size){
  double sum = 0;
  for(int i = 0; i< size; i++){
    sum += proc[i].tat;
  }

  return sum / (double)size;
}

double average_wt(Process *proc, int size){
  double sum = 0;
  for(int i = 0; i< size; i++){ 
    sum += proc[i].wt;
  }

  return sum / (double)size;
}

int main(){
  int size; scanf("%d", &size);
  Process proc[size];

  read_proc(proc, size);
  sort(proc, size);
  calc_ct(proc, size);
  calc_wt(proc, size);
  calc_tat(proc, size);
  double avg_tat = average_tat(proc, size);
  double avg_wt  = average_wt(proc, size);
  
  printf("\nArrival time  Burst time  Completion time  Turn around time  Waiting time\n");
  for(int i = 0; i<size; i++)
    printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", proc[i].arrival_time, proc[i].burst_time, proc[i].ct, proc[i].tat, proc[i].wt);
  
  printf("Average Turnaround time %.2f\nAverage waiting time %.2f\n", avg_tat, avg_wt);

  return 0;
}
 





