#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random1to100();
void printAr(int numAr[], int numArSize);
int checkNum(int numAr[], int numArSize);
int searchNum(int numAr[], int numArSize, int target);
void sortArray(int numAr[], int numArSize);  // ???????????????????????
int binarySearchNum(int numAr[], int numArSize, int target);

int main() {
    int N, i;
    int A[100];
    
    printf("Enter number of elements (1-100): ");
    scanf("%d", &N);
    
    if (N > 100)
        N = 100;
    
    srand(time(NULL));
    
    for (i = 0; i < N; i++) {
        A[i] = checkNum(A, i);
        sortArray(A, i + 1);  // ????????????????????????????????????
    }
    
    printf("\n**********\n");
    printf("Generated array with unique numbers (sorted):\n");
    printAr(A, N);
    
    return 0;
}

int random1to100() {
    return (rand() % 100) + 1;
}

void printAr(int numAr[], int numArSize) {
    for (int i = 0; i < numArSize; i++) {
        printf("%d ", numAr[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

int checkNum(int numAr[], int numArSize) {
    int rnum;
    rnum = random1to100();
    
    while (binarySearchNum(numAr, numArSize, rnum)) {
        rnum = random1to100();
    }
    return rnum;
}

int binarySearchNum(int numAr[], int numArSize, int target) {
    int left = 0, right = numArSize - 1;
    int mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        if (numAr[mid] == target)
            return 1;
        else if (numAr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

void sortArray(int numAr[], int numArSize) {
    for (int i = 1; i < numArSize; i++) {
        int key = numAr[i];
        int j = i - 1;
        
        while (j >= 0 && numAr[j] > key) {
            numAr[j + 1] = numAr[j];
            j = j - 1;
        }
        numAr[j + 1] = key;
    }
}

int linearSearchNum(int numAr[], int numArSize, int target) {
    for (int i = 0; i < numArSize; i++) {
        if (numAr[i] == target)
            return 1;
    }
    return 0;
}