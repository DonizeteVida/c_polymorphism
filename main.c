#include <stdio.h>

typedef struct {
    int vertices;
} Shape;

typedef struct {
    Shape shape;
    int faces;
} Square;

typedef struct {
    void (*howManyVertices)(Shape*);
} ShapeInterface;

static void passCallback(ShapeInterface* shapeInterface, Shape* shape) {
    shapeInterface->howManyVertices(shape);
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
    
    ShapeInterface interface = {
        .howManyVertices = &callback
    };

    passCallback(&interface, &square);
}