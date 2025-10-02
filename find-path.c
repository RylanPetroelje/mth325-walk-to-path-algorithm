#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // Geeks for Geeks
        int vertex;
        int position;
} Vertex; // Alias

typedef struct { 
        Vertex* ptr;
        int size; //size allocated for Walk
        int top; //current index of top vertex
} Walk;

void push(Walk* walk, Vertex vertex);
void pop(Walk* walk);
Vertex* scanWalk(Walk* walk, int vertex);
void dump(Walk* walk);

int main(void) {

    Walk walk;
    walk.top = -1;
    walk.size = 100;
    walk.ptr = (Vertex*)malloc(sizeof(Vertex) * walk.size);

    char* buffer = NULL;
    size_t bufferSize = 0;

    printf("Enter your walk vertices without delimiters e.g. 12314565786:\n");
    getline(&buffer, &bufferSize, stdin);

    int len = strlen(buffer);
    if (buffer[len-1] == '\n'){
        buffer[len-1] = 0; //gets rid of newline and null terminates
        len--;
    }

    for (int i=0; i<len; i++){
        int vertex = buffer[i] - '0'; //turns the char into an integer (GeeksForGeeks)
        Vertex* scan = scanWalk(&walk, vertex);
        if (scan){
            while ((walk.top >= 0) && (walk.ptr[walk.top].vertex != vertex)) {
                pop(&walk);
            }
            //pop(&walk);
        } else {
            Vertex v;
            v.vertex = vertex;
            v.position = i;
            push(&walk, v);
        }
    }

    printf("Path:\n");
    dump(&walk);

    free(buffer);
    free(walk.ptr);

    return 0;
}

void push(Walk* walk, Vertex vertex){
    if (walk->top >= walk->size-1) {
        walk->size *= 2;
        walk->ptr = realloc(walk->ptr, sizeof(Vertex) * walk->size);
    } //accounts for running out of room in the Walk
    walk->top++; //moves pointer to the top up one
    walk->ptr[walk->top] = vertex; //puts new vertex at the top
}

void pop(Walk* walk) {
    if (walk->top >= 0){
        walk->top--;
    }
}

Vertex* scanWalk(Walk* walk, int vertex) {
    for (int i=0; i<=walk->top; i++) {
        if (walk->ptr[i].vertex == vertex) {
            return &walk->ptr[i];
        }
    }
    return NULL;
}

void dump(Walk* walk) {
    for (int i=0; i<=walk->top; i++) {
        printf("%d", walk->ptr[i].vertex);
    }
    printf("\n");
}
