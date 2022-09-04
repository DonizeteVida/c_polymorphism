#include <stdio.h>

#define Function0(return, name) return (*name)(void)
#define Function1(return, name, p1) return (*name)(p1)
#define Cast(is, as) (as) is

typedef struct Shape Shape;

typedef struct {
    Function1(void, incrementVertices, Shape *);
} ShapeInterface;

struct Shape {
    int vertices;
    ShapeInterface interface;
};

typedef struct {
    Shape shape;
    int faces;
} Square;

typedef Function1(void, VoidCallback, void *);

static void passCallback(VoidCallback callback, void *context) {
    callback(context);
}

static void incrementVertices(Shape *this) {
    printf("Vertices: %d\n", this->vertices);
    this->vertices++;
    printf("Vertices: %d\n", this->vertices);
}

int main(int argc, char *argv[]) {
    printf("Hello World\n");
    Square square = {
        .shape = {
            .vertices = 8,
            .interface = {
                .incrementVertices = &incrementVertices
            }
        },
        .faces = 6
    };

    passCallback(Cast(square.shape.interface.incrementVertices, VoidCallback), &square);
}