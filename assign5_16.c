#include<stdio.h>

int main(){

    int runs[11];
    int hashTable[11];
    
     for(int i=0;i<11;i++){
        hashTable[i]=-1;
    }

    printf("Enter the runs for each player:- ");
    for(int i=0;i<11;i++){
        printf("Player %d: ",i+1);
        scanf("%d",&runs[i]);
    
    int index = runs[i] % 11;

    while(hashTable[index] != -1){
        index=(index+1) % 11;

        }

    hashTable[index] = i + 1;

    }

    printf("\nHash Table (Rank# => Player):\n");
    for(int i=0;i<11;i++){
        if(hashTable[i] != -1){
            printf("Rank %d => Player %d\n",i,hashTable[i] );
        }
        else{
            printf("Rank %d => Empty\n",i);
        }
    }
    return 0;
}
