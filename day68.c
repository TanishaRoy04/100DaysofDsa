#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

// Topological Sort using Kahn's Algorithm
void topologicalSort(int graph[MAX][MAX], int V) {
    int inDegree[MAX] = {0};
    int topoOrder[MAX];
    int count = 0;

    // Step 1: Calculate in-degrees
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    // Step 2: Add nodes with in-degree 0 to queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            enqueue(i);
        }
    }

    // Step 3: Process the queue
    while (!isEmpty()) {
        int node = dequeue();
        topoOrder[count++] = node;

        for (int i = 0; i < V; i++) {
            if (graph[node][i] == 1) {
                inDegree[i]--;

                if (inDegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != V) {
        printf("Graph has a cycle. Topological sort not possible.\n");
        return;
    }

    // Print result
    printf("Topological Order:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", topoOrder[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int V = 6;

    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(graph, V);

    return 0;
}