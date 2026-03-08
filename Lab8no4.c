#include <stdio.h>

void printAr(int numAr[], int numArSize);
int findMaxIndex(int numAr[], int numArSize);
void removeElement(int numAr[], int *numArSize, int index);

int main() {
    int scores[4] = {75, 82, 68, 91};
    int temp[4];
    int size = 4;
    int best3[3];
    
    for(int i = 0; i < size; i++) {
        temp[i] = scores[i];
    }
    
    printf("All 4 scores: ");
    printAr(scores, size);
    
    int tempSize = size;
    for(int i = 0; i < 3; i++) {
        int maxIndex = findMaxIndex(temp, tempSize);
        best3[i] = temp[maxIndex];
        removeElement(temp, &tempSize, maxIndex);
    }
    
    printf("Top 3 scores: ");
    printAr(best3, 3);
    
    return 0;
}

void printAr(int numAr[], int numArSize) {
    printf("[");
    for(int i = 0; i < numArSize; i++) {
        printf("%d", numAr[i]);
        if(i < numArSize - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

int findMaxIndex(int numAr[], int numArSize) {
    int maxIndex = 0;
    for(int i = 1; i < numArSize; i++) {
        if(numAr[i] > numAr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void removeElement(int numAr[], int *numArSize, int index) {
    for(int i = index; i < *numArSize - 1; i++) {
        numAr[i] = numAr[i + 1];
    }
    (*numArSize)--;
}