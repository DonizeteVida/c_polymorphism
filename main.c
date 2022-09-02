#include <stdio.h>

typedef struct {
    int vertices;
} Shape;

typedef struct {
    Shape shape;
    int faces;
} Square;

static void passCallback(void (*callback)(void*), void* context) {
    callback(context);
}

static void callback(Shape* shape) {
    printf("Vertices: %d\n", shape->vertices);
}

int main(int argc, char* argv[]) {
    printf("Hello World\n");
    Square square = {
        .shape = {
            .vertices = 8
        },
        .faces = 6
    };

    passCallback(&callback, &square);
}