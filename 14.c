#include <stdio.h>
#define SIZE 10

int hash[SIZE];

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        scanf("%d",&key);
        int index = key % SIZE;
        hash[index] = key;
    }

    for(int i=0;i<SIZE;i++)
        printf("%d -> %d\n",i,hash[i]);
}