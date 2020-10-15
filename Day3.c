#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ResReq(char Pname[50][10],int AVAIL[50],int MAXIMUM[50][50],int ALLOC[50][50],int NEED[50][50],int nP,int nR){
    int i,additional_req[1][50],flag = -1;
    char pid[10];
    printf("Enter Process Name: ");
    scanf("%s",pid);
    for(i=0;i<nP;i++){
        if(strcmpi(pid,Pname[i]) == 0){
            flag = i;
            break;
        }else
            flag = -1;
    }
    if(flag == -1){
        printf("Error: Process not found!\n\n");
        return;
    }
        
    printf("Enter additional request:\n ");
    for(i=0;i<nR;i++){
		printf("Request for resource %d: ",i+1);
		scanf("%d",&additional_req[0][i]);
	}
    for(i=0;i<nR;i++)
		if(additional_req[0][i] > NEED[flag][i]){
			printf("\nError encountered (Entered Resource is more than allocated)\n");
			exit(0);
	}
    for(i=0;i<nR;i++)
		if(additional_req[0][i] > AVAIL[i]){
			printf("\nResources unavailable (All instances are busy)\n");
			exit(0);
		}
    for(i=0;i<nR;i++){
		AVAIL[i]-=additional_req[0][i];
		ALLOC[flag][i]+=additional_req[0][i];
		NEED[flag][i]-=additional_req[0][i];
	}
    printf("Allocated Successfully!\n");
}
void ProcessData(char Pname[50][10],int AVAIL[50],int MAXIMUM[50][50],int ALLOC[50][50],int nP,int nR){
    int NEED[50][50],i,j,k,Tmp[50],p;
    for(i=0;i<nP;i++)
        for(j=0;j<nR;j++)
            NEED[i][j] = MAXIMUM[i][j] - ALLOC[i][j];
    int completed[50] = {0};
    char sequence[50][10];
    for(i=0;i<nR;i++)
        Tmp[i] = AVAIL[i];
    int total_process = 0;
    while(total_process < nP){
        int flag = 0;
        for(i=0;i<nP;i++){
            if(completed[i] == 0){
                for(j=0;j<nR;j++){
                    if(NEED[i][j] > Tmp[j])
                        break;
                }
                if(j == nR){
                    for(p=0;p<nR;p++){
                        Tmp[p] += ALLOC[i][p];
                    }
                    strcpy(sequence[total_process++],Pname[i]);
                    completed[i] = 1;
                    flag = 1;
                }
            }
        }
        if(flag == 0){
            printf("System not Safe State!");
            return;
        }
    }
    printf("System in Safe State!\n");
    for(i=0;i<5;i++)
        printf("%s ",sequence[i]);
    while(1){
		printf("\nRequest New Resource?(0/1): ");
		int opt;
		scanf("%d",&opt);
		if(opt == 1)
			ResReq(Pname,AVAIL,MAXIMUM,ALLOC,NEED,nP,nR);
		else
			break;
    }
}
int main(){
    int nP,nR,i,j;
    char Pname[50][10];
    int AVAIL[50],MAXIMUM[50][50],ALLOC[50][50];
    printf("Enter the number of Processes:");
	scanf("%d",&nP);
    printf("Enter the number of Resources:");
	scanf("%d",&nR);
    printf("Enter names of Processes: ");
    for(i = 0; i<nP;i++){
        scanf("%s",Pname[i]);
    }
    printf("Enter Instance of each Resource: ");
    for(i = 0; i<nR;i++){
        scanf("%d",&AVAIL[i]);
    }
    printf("Enter Max resource of each Process: ");
    for(i = 0; i < nP ;i++){
        printf("\n%s:\n",Pname[i]);
        for(j = 0; j<nR;j++){
            printf("Resource %d : ",j+1);
            scanf("%d",&MAXIMUM[i][j]);
        }
    }
	printf("Enter Alloted resource of each Process: ");
	for(i = 0; i < nP ;i++){
        printf("\n%s:\n",Pname[i]);
        for(j = 0; j<nR;j++){
            printf("Resource %d : ",j+1);
            scanf("%d %d",&ALLOC[i][j]);
        }
    }
    ProcessData(Pname,AVAIL,MAXIMUM,ALLOC,nP,nR);
}