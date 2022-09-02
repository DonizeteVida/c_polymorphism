#include <stdio.h>

typedef struct {
    int vertices;
} Shape;

typedef struct {
    Shape shape;
    int faces;
} Square;

int main(int argc, char* argv[]) {
    printf("Hello World\n");
    Square square = {
        .shape = {
            .vertices = 8
        },
        .faces = 6
    };
    Shape* shape = &square;
    int* vertices = &square;
    printf("Vertices: %d\n", *vertices);
    printf("Vertices: %d\n", shape->vertices);
}