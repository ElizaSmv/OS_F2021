#include <stdio.h>
#include <limits.h>

#define N 3  //number of processes

typedef struct Process{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int flag; 
} Process;

int main(){
    Process Pr[N];
    printf("Number of processes %d\n", N);
    for (int i = 0; i < N; i++) {
        printf("Arrival time for process %d ", i+1, "\n");
        scanf("%d", &Pr[i].at);
        printf("Burst time for process %d ", i+1, "\n");
        scanf("%d", &Pr[i].bt);
        Pr[i].wt = 0; Pr[i].tat = 0; Pr[i].ct = 0; Pr[i].flag=0;

    }
    int total_time = 0;
    for (int k = 0; k < N; k++) {
        int min = INT_MAX; //min at
        int p = -1;
        for (int i = 0; i < N; i++) {
            if (Pr[i].at <= min && !Pr[i].flag) {
                min = Pr[i].at;
                p = i;
            }
        }

        if (min > total_time) {
            total_time = min;
            Pr[p].wt = 0;
        } else {
            Pr[p].wt = total_time - min;
        }
        Pr[p].ct = total_time + Pr[p].bt;
        total_time = Pr[p].ct;
        Pr[p].flag = 1;
        Pr[p].tat = Pr[p].ct - Pr[p].at;
    }
    double av_tat = 0, av_wt = 0;
    printf("P#   AT   BT   CT   TAT   WT\n");
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("P%d   %d   %d   %d   %d   %d\n", i + 1, Pr[i].at,Pr[i].bt,Pr[i].ct,Pr[i].tat,Pr[i].wt);
        av_tat += Pr[i].tat;
        av_wt += Pr[i].wt;
    }
    av_tat = av_tat / N;
    av_wt = av_wt / N;
    printf("Average TAT %f \n", av_tat);
    printf("Average WT %f\n", av_wt);
}
