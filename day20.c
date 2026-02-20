#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 100003   // A large prime number

typedef struct Node {
    long long sum;
    long long count;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

// Hash function
int hash(long long key) {
    if (key < 0) key = -key;
    return key % HASH_SIZE;
}

// Insert or update prefix sum frequency
long long insert(long long sum) {
    int index = hash(sum);
    Node* temp = hashTable[index];
    
    while (temp != NULL) {
        if (temp->sum == sum) {
            temp->count++;
            return temp->count - 1;  // return previous count
        }
        temp = temp->next;
    }
    
    // If not found, create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long *arr = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long prefix_sum = 0;
    long long result = 0;

    // Important: prefix sum 0 appears once initially
    insert(0);

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        result += insert(prefix_sum);
    }

    printf("%lld\n", result);

    return 0;
}