#include<stdio.h>
#include <stdlib.h>
int no_of_frames, no_of_pages, pages[30], frames[10];
void accept_values(){
	printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);
	printf("Enter number of pages: ");
	scanf("%d", &no_of_pages);
	printf("Enter values of page: ");
	for(int i = 0; i < no_of_pages; i++){
	scanf("%d", &pages[i]);
}
}
int findLRU(int time[], int n){
	int i, minimum = time[0], pos = 0;
	for(i = 1; i < n; ++i){
		if(time[i] < minimum){
			minimum = time[i];
			pos = i;
		}
	}
	return pos;
}
void LRU(){
    int counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    printf("   FRAME CONTENT   \n");
    for(i = 0; i < no_of_pages; ++i){
    	flag1 = flag2 = 0;
    	for(j = 0; j < no_of_frames; ++j){
    		if(frames[j] == pages[i]){
	    		counter++;
	    		time[j] = counter;
	   			flag1 = flag2 = 1;
	   			break;
   			}
    	}
    	
    	if(flag1 == 0){
			for(j = 0; j < no_of_frames; ++j){
	    		if(frames[j] == -1){
	    			counter++;
	    			faults++;
	    			frames[j] = pages[i];
	    			time[j] = counter;
	    			flag2 = 1;
	    			break;
	    		}
    		}	
    	}
    	if(flag2 == 0){
    		pos = findLRU(time, no_of_frames);
    		counter++;
    		faults++;
    		frames[pos] = pages[i];
    		time[pos] = counter;
    	}
        printf("\n");
        if(flag2 != 0 && flag1 != 0)
            printf("%d\t: ",pages[i]);
        else
            printf("%d (X)\t: ",pages[i]);
    	for(j = 0; j < no_of_frames; ++j){
    		if(frames[j] == -1)
                printf(" ");
            else
                printf("%d\t",frames[j]);
    	}
	}
	printf("\nNumber of page fault: %d\n\n",faults);
}
void FIFO(){
    int i,j,n,k,avail,count=0;
    j=0;
    printf("   FRAME CONTENT   \n");
    for(i=0;i<no_of_pages;i++){
        avail=0;
        for(k=0;k<no_of_frames;k++)
            if(frames[k] == pages[i])
                avail=1;
        if(avail == 1)
            printf("%d\t: ",pages[i]);
        else
            printf("%d (X)\t: ",pages[i]);
        if (avail==0){
            frames[j]=pages[i];
            j=(j+1)%no_of_frames;
            count++;
            for(k=0;k<no_of_frames;k++)
                if(frames[k] == -1)
                    printf(" ");
                else
                    printf("%d\t",frames[k]);
        }else{
            for(k=0;k<no_of_frames;k++)
                if(frames[k] == -1)
                    printf(" ");
                else
                    printf("%d\t",frames[k]);
        }
        printf("\n");
    }
    printf("Number of page fault: %d\n\n",count);
}
int getFreqPos(int curr){
    int a[10],flag = 0;
    for(int j=0; j<no_of_frames; j++){
        a[j] = 0;
        for(int i=0; i<curr; i++){
            if(frames[j] == pages[i])
                a[j]++;
        }
    }
    int min = 0,framepos[10], m = 0,tt=0;      
    for(int i=1; i<no_of_frames; i++){
        if(a[min] > a[i]){
            min = i;
        }
    }
    int f1 = 0,max = 99,fmin = min;
    for(int j=0; j<no_of_frames; j++){
        if(a[j] == a[min]){
            for(int k=0;k<no_of_pages;k++){
                if(frames[j] == pages[k]){
                    if(max > k){
                        max = k;
                        fmin = j; 
                    }   
                    break;
                }
            }
        }
    }
    return fmin;
}
void LFU(){
    int fault_count = 0;
    printf("   FRAME CONTENT   \n");
    for(int i=0; i<no_of_pages; i++){
        int j,isFault = 0;
        for(j=0; j<no_of_frames; j++)
            if(pages[i] == frames[j] || frames[j] == -1){
                isFault = 0;
                if(frames[j] == -1)
                    isFault = 1;
                break;
            }
        if(j == no_of_frames){
            int pos = getFreqPos(i);
            isFault = 1;
            frames[pos] = pages[i];
        }else{ 
            frames[j] = pages[i];
        }
        if(isFault == 0)
            printf("%d\t: ",pages[i]);
        else{
            printf("%d (X)\t: ",pages[i]);
            fault_count++;
        }
        for(int k=0; k<no_of_frames; k++)
            if(frames[k] == -1)
                printf(" \t");
            else
                printf("%d\t",frames[k]);
        printf("\n");
    }
    printf("Number of page fault: %d\n\n",fault_count);
}
int main(){
    int opt;
    printf("\n****************\n");
    printf("**   Gokul S  **\n");
    printf("** RET18CS079 **\n");
    printf("****************\n");
    accept_values();
    while(1){
        for(int i = 0; i < no_of_frames; ++i)
    	    frames[i] = -1;
        printf("Select a Page Replacement algorithms:\n1. FIFO\n2. LRU\n3. LFU\n4. Exit\n==>");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                FIFO();
                break;
            case 2:
                LRU();
                break;
            case 3:
                LFU();
                break;
            case 4:
                exit(0);
        }
    }
}
