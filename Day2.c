#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTALS 15
void singleLevel(){
    struct{
        char Dir[TOTALS],Filename[TOTALS][TOTALS];
        int filecount;
    }directory;
    int opt;
    directory.filecount = 0;
    printf("Enter name of the directory: ");
    scanf("%s",directory.Dir);
    while(1){
        printf("\n1.Create File\n2.Delete File\n3.Search File\n4.Display Files\n5.Exit\nEnter Choice:");
        scanf("%d",&opt);
        int i;
        switch(opt){
            case 1:
                printf("Enter the name of the file: ");
                char CreateName[TOTALS];
                scanf("%s",CreateName);
                for(i = 0; i<directory.filecount; i++){
                   if(strcmp(CreateName,directory.Filename[i]) == 0){
                       break;
                   }
                }
                if(i == directory.filecount){
                    strcpy(directory.Filename[directory.filecount],CreateName);
                    directory.filecount++;
                    printf("File Created.\n");
                }else
                    printf("File Already Exists.\n");
                break;
            case 2:
                if(directory.filecount == 0){
                    printf("Directory Empty.\n");
                    break;
                }
                printf("Select File to delete: ");
                for(int i = 0; i<directory.filecount; i++){
                    printf("%s\n",directory.Filename[i]);
                }
                char delName[TOTALS];
                scanf("%s",delName);
                for(i = 0; i<directory.filecount; i++){
                    if(strcmp(delName,directory.Filename[i]) == 0){
                       strcpy(directory.Filename[i],directory.Filename[directory.filecount-1]);
                       break;
                   }
                }
                if(i == directory.filecount)
                    printf("File Not Found!.\n");
                else{
                    directory.filecount--;
                    printf("File Deleted.\n");
                }
                break;
            case 3:
                printf("Enter a file Name: ");
                char Sname[TOTALS];
                scanf("%s",Sname);
                int flag = 0;
                for(i = 0; i<directory.filecount; i++){
                    if(strcmp(Sname,directory.Filename[i]) == 0){
                        printf("File Found.\n");
                        flag = 1;
                    }
                }
                if(flag == 0)
                    printf("File Not Found!.\n");
                break;
            case 4:
                if(directory.filecount == 0){
                    printf("No Files are in this Directory.\n");
                }else{
                    printf("Files in %s :\n",directory.Dir);
                    for(int i=0; i< directory.filecount;i++){
                        printf("%d. %s\n",i+1,directory.Filename[i]);
                    }
                }
                break;
            case 5:
                exit(0);
        }
    }
}
void twoLevel(){
    struct{
        char Dir[TOTALS],Filename[TOTALS][TOTALS];
        int filecount;
    }directory[TOTALS];
    int opt,DirCount = 0;
    for(int i=0; i<TOTALS;i++){
        directory[i].filecount = 0;
    }
    char rootdir[TOTALS];
    printf("Enter name of root Dir: ");
    scanf("%s",rootdir);
    while(1){
        printf("\n1.Create Directory\n2.Create File\n3.Delete File\n4.Search File\n5.Display Files\n6.Exit\nEnter Choice:");
        scanf("%d",&opt);
        int i,dirID;
        char tmpdirname[TOTALS];
        switch(opt){
            case 1:
                printf("Enter the name of the Directory: ");
                char CreateDir[TOTALS];
                scanf("%s",CreateDir);
                for(i = 0; i<DirCount; i++){
                   if(strcmp(CreateDir,directory[i].Dir) == 0){
                       break;
                   }
                }
                if(i == DirCount){
                    strcpy(directory[i].Dir,CreateDir);
                    DirCount++;
                    printf("Directory Created.\n");
                }else
                    printf("Directory Already Exists.\n");
                break;
            case 2:
                printf("Enter the name of the Directory: ");
                scanf("%s",tmpdirname);
                for(dirID = 0;dirID < DirCount;dirID++){
                    if(strcmp(directory[dirID].Dir,tmpdirname)==0)
                        break;
                }
                if(dirID == DirCount){
                    printf("Directory Invalid\n");
                    break;
                }
                printf("Enter the name of the file: ");
                char CreateName[TOTALS];
                scanf("%s",CreateName);
                for(i = 0; i<directory[dirID].filecount; i++){
                   if(strcmp(CreateName,directory[dirID].Filename[i]) == 0){
                       break;
                   }
                }
                if(i == directory[dirID].filecount){
                    strcpy(directory[dirID].Filename[directory[dirID].filecount],CreateName);
                    directory[dirID].filecount++;
                    printf("File Created.\n");
                }else
                    printf("File Already Exists.\n");
                break;
            case 3:
                printf("Enter the name of the Directory: ");
                scanf("%s",tmpdirname);
                for(dirID = 0;dirID < DirCount;dirID++){
                    if(strcmp(directory[dirID].Dir,tmpdirname)==0)
                        break;
                }
                if(dirID == DirCount){
                    printf("Directory Invalid\n");
                    break;
                }
                if(directory[dirID].filecount == 0){
                    printf("Directory Empty.\n");
                    break;
                }
                printf("Select File to delete: ");
                for(int i = 0; i<directory[dirID].filecount; i++){
                    printf("%s\n",directory[dirID].Filename[i]);
                }
                char delName[TOTALS];
                scanf("%s",delName);
                for(i = 0; i<directory[dirID].filecount; i++){
                    if(strcmp(delName,directory[dirID].Filename[i]) == 0){
                       strcpy(directory[dirID].Filename[i],directory[dirID].Filename[directory[dirID].filecount-1]);
                       break;
                   }
                }
                if(i == directory[dirID].filecount)
                    printf("File Not Found!.\n");
                else{
                    directory[dirID].filecount--;
                    printf("File Deleted.\n");
                }
                break;
            case 4:
                printf("Enter a file Name: ");
                char Sname[TOTALS];
                scanf("%s",Sname);
                int flag = 0;
                for(dirID = 0;dirID < DirCount;dirID++){
                    for(i = 0; i<directory[dirID].filecount; i++){
                        if(strcmp(Sname,directory[dirID].Filename[i]) == 0){
                            printf("File Found. in Directory %s\n",directory[dirID].Dir);
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 1)
                        break;
                }
                if(flag != 1)
                    printf("File Not Found!.\n");
                break;
            case 5:
                printf("Root Dir: %s\n",rootdir);
                for(dirID = 0;dirID < DirCount;dirID++){
                    printf("%s\n",directory[dirID].Dir);
                    if(directory[dirID].filecount == 0){
                        printf("-- No Files\n");
                        break;
                    }else
                        for(int i=0; i< directory[dirID].filecount;i++){
                            printf("-- %d. %s\n",i+1,directory[dirID].Filename[i]);
                        }
                }
                break;
            case 6:
                exit(0);
        }
    }
}
struct dir_node{
        char Dirname[TOTALS],FileNames[TOTALS][TOTALS];
        int DirCount,FileCount;
        struct dir_node *link[TOTALS]; 
}*root,*current;
typedef struct dir_node node;
void printSpace(int n){
    for(int i=0; i<n; i++)
        printf("--");
}
void StructureDisplay(node *S,int space){
    if(S != NULL){
        if(S==root)
            printf("%s (Root)\n",S->Dirname);
        else
            printf("%s (Folder)\n",S->Dirname);
        for(int i=0; i<S->DirCount; i++){
            printSpace(space);
            StructureDisplay(S->link[i],space+1);
        }
        for(int i=0; i<S->FileCount; i++){
            printSpace(space);
            printf("%s (File)\n",S->FileNames[i]);
        }
    }
}
node* createDir(){
    node *NODE = (node *) malloc(sizeof(node));
    printf("Enter name of Directory: ");
    scanf("%s",NODE->Dirname);
    NODE->DirCount = 0;
    NODE->FileCount = 0;
    for(int i=0; i<TOTALS; i++)
        NODE->link[i] = NULL;
    printf("Directory Created.\n");
    return NODE;
}
void hierarLevel(){
    int opt;
    root = createDir();
    current = root;
    while(1){
        printf("\nCurrent Directory: %s",current->Dirname);
        printf("\n\n1.Create Directory\n2.Create File\n3.Delete File\n4.Search File\n5.Display Structure\n6.Change Directory\n7.Exit\nEnter Choice:");
        scanf("%d",&opt);
        char name[TOTALS];
        int opt1;
        switch(opt){
            case 1:
                current->link[current->DirCount] = createDir();
                current->DirCount++;
                break;
            case 2:
                printf("Enter File Name: ");
                scanf("%s",current->FileNames[current->FileCount]);
                current->FileCount++;
                break;
            case 3:
                if(current->FileCount == 0){
                    printf("No Files in this directory.");
                    break;
                }
                printf("Enter File Name to Delete: ");
                scanf("%s",name);
                int i;
                for(i=0; i<current->FileCount; i++){
                    if(strcmp(name,current->FileNames[i])==0){
                        strcpy(current->FileNames[i],current->FileNames[current->FileCount-1]);
                        break;
                    }
                }
                if(i == current->DirCount){
                    printf("File Not Found.\n");
                }else{
                    current->FileCount--;
                    printf("File Deleted.\n");
                }
                break;
            case 4:
                if(current->FileCount == 0){
                    printf("No Files in this directory.");
                    break;
                }
                printf("Enter File Name to Search: ");
                scanf("%s",name);
                for(i=0; i<current->FileCount; i++){
                    if(strcmp(name,current->FileNames[i])==0){
                        break;
                    }
                }
                if(i == current->DirCount){
                    printf("File Not Found.\n");
                }else{
                    printf("File Found.\n");
                }
                break;
            case 5:
                printf("\nCurrent File Structure\n");
                StructureDisplay(root,1);
                break;
            case 6:
                printf("\n1.Go to Root\n2.Go Up to Dir\nEnter option:");
                scanf("%d",&opt1);
                switch(opt1){
                    case 1:
                        current = root;
                        printf("Directory Changed to %s: \n",root->Dirname);
                        break;
                    case 2:
                        printf("Enter a Directory:");
                        scanf("%s",name);
                        int k,fleg = 1;
                        for(k=0; k<current->DirCount; k++){
                            if(strcmp(current->link[k]->Dirname,name) == 0){
                                printf("Directory Changed to %s: \n",name);
                                current = current->link[k];
                                fleg = 0;
                                break;
                            }
                        }
                        if(fleg == 1){
                            printf("Directory Not Found\n");
                        }
                        break;
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Option\n");
        }
    }
}
int main(){
	int opt_dir;
    printf("\n****************\n");
    printf("**   Gokul S  **\n");
    printf("** RET18CS079 **\n");
    printf("****************\n");
	printf("Select a File Stratergy: \n1. Single level Directory\n2. Two level Directory\n3. Hierarchical Directory\n-->");
    scanf("%d",&opt_dir);
    switch (opt_dir)
    {
    case 1:
        singleLevel();
        break;
    case 2:
        twoLevel();
        break;
    case 3:
        hierarLevel();
        break;
    default:
        break;
    }
}