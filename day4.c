#include <stdio.h>
#include <stdlib.h>
#define LEN 20
int no_req,init_head,queue_io[LEN];
void accept_values(){
    printf("Enter the total number of queue elements:");
    scanf("%d",&no_req);
    printf("Enter the initial head position:");
    scanf("%d",&init_head);
    printf("Enter the I/O requests:\n");
    for(int i=1; i<=no_req; i++){
        printf("Request %d: ",i);
        scanf("%d",&queue_io[i]);
    }
}
void FCFS(){
    queue_io[0] = init_head;
    int seek = 0;
    printf("\n\nFCFS\n*****\nOrder: ");
    for(int i=0; i<no_req; i++){
        if(i < no_req - 1)
            printf(" %d ==>",queue_io[i]);
        else
            printf(" %d \n",queue_io[i]);
        seek += abs(queue_io[i]-queue_io[i+1]);
    }
    printf("Total Seek time: %d\nAverage Seek time: %.2f\n\n",seek,(float)seek/no_req);
}
void SCAN(){
    queue_io[++no_req] = init_head;
    no_req++;
    int head_pos;
    printf("\n\nSCAN\n*****\nOrder: ");
    for(int i=1; i<no_req;i++){
        for(int j=i; j<no_req; j++){
            if(queue_io[i]<queue_io[j]){
                int temp = queue_io[i];
                queue_io[i] = queue_io[j];
                queue_io[j] = temp;
            }
        }
    }
    for(int i=1; i<no_req; i++){
        if(init_head == queue_io[i]){
            head_pos = i;
            break;
        }
    }
    if(abs(init_head-0) <= abs(init_head-199)){
        for(int j=head_pos; j>=1; j--){
            if(j < no_req - 1)
                printf(" %d ==>",queue_io[j]);
            else
                printf(" %d \n",queue_io[j]);
        }
        for(int j=head_pos+1; j<no_req; j++){
            if(j < no_req - 1)
                printf(" %d ==>",queue_io[j]);
            else
                printf(" %d \n",queue_io[j]);
        }
    }else{
        for(int j=head_pos+1; j<no_req; j++){
            if(j < no_req - 1)
                printf(" %d ==>",queue_io[j]);
            else
                printf(" %d \n",queue_io[j]);
        }
        for(int j=head_pos; j>=1; j--){
            if(j < no_req - 1)
                printf(" %d ==>",queue_io[j]);
            else
                printf(" %d \n",queue_io[j]);
        }
    }
    int seek = (199-init_head)+(199-queue_io[no_req-1]);
    printf("Total Seek time: %d\nAverage Seek time: %.2f\n\n",seek,(float)seek/no_req);
}
void CSCAN(){
    int i,j,k,seek=0,temp,queue1[20],queue2[20],temp1=0,temp2=0;
    printf("Enter the total number of queue elements:");
    scanf("%d",&no_req);
    printf("Enter the initial head position:");
    scanf("%d",&init_head);
    printf("Enter the I/O requests:\n");
    for(i=1;i<=no_req;i++){
        printf("Requests %d:",i);
        scanf("%d",&temp);
        if(temp>=init_head){
            queue1[temp1]=temp;
            temp1++;
        }else{
            queue2[temp2]=temp;
            temp2++;
        }
    }
    for(i=0;i<temp1-1;i++){
        for(j=i+1;j<temp1;j++){
            if(queue1[i]>queue1[j]){
                temp=queue1[i];
                queue1[i]=queue1[j];
                queue1[j]=temp;
            }
        }
    }
    for(i=0;i<temp2-1;i++){
        for(j=i+1;j<temp2;j++){
            if(queue2[i]>queue2[j]){
                temp=queue2[i];
                queue2[i]=queue2[j];
                queue2[j]=temp;
            }
        }
    }
    for(i=1,j=0;j<temp1;i++,j++)
        queue_io[i]=queue1[j];
    queue_io[i]=199;
    queue_io[i+1]=0;

    for(i=temp1+3,j=0;j<temp2;i++,j++)
        queue_io[i]=queue2[j];
    queue_io[0]=init_head;

    printf("\n\nCSCAN\n*****\nOrder: ");
    for(j=0;j<=no_req+1;j++){
        if(j < no_req + 1)
            printf(" %d ==>",queue_io[j]);
        else
            printf(" %d \n",queue_io[j]);
        seek += abs(queue_io[j+1]-queue_io[j]);
    }
    printf("Total Seek time: %d\nAverage Seek time: %.2f\n\n",seek,seek/(float)no_req);
}
int main(){
    int opt;
    printf("\n****************\n");
    printf("**   Gokul S  **\n");
    printf("** RET18CS079 **\n");
    printf("****************\n");
    while(1){
        printf("Select a Disk Scheduling algorithms:\n1. FCFS\n2. SCAN\n3. C-SCAN\n4. Exit\n==>");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                accept_values();
                FCFS();
                break;
            case 2:
                accept_values();
                SCAN();
                break;
            case 3:
                CSCAN();
                break;
            case 4:
                exit(0);
        }
    }
}