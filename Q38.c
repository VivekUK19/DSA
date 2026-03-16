#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int size() {
    if (isEmpty())
        return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
    } else if (front > 0) {
        front--;
    } else {
        printf("Deque Overflow\n");
        return;
    }
    deque[front] = x;
}

void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear++;
    deque[rear] = x;
}

void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    front++;
    if (front > rear)
        front = rear = -1;
}

void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    rear--;
    if (rear < front)
        front = rear = -1;
}

int getFront() {
    if (isEmpty())
        return -1;
    return deque[front];
}

int getBack() {
    if (isEmpty())
        return -1;
    return deque[rear];
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {
    int n, value;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &value);
            push_front(value);
        }

        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &value);
            push_back(value);
        }

        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }

        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }

        else if (strcmp(op, "front") == 0) {
            printf("%d\n", getFront());
        }

        else if (strcmp(op, "back") == 0) {
            printf("%d\n", getBack());
        }

        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }

        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
    }

    display();

    return 0;
}