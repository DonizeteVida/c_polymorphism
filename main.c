#include <stdio.h>

#define Function0(name, out) out (*name)(void)
#define Function1(name, out, p1) out (*name)(p1)
#define Cast(from, to) (to) from

typedef struct {
    int vertices;
} Shape;

typedef struct {
    Shape shape;
    int faces;
} Square;

typedef Function1(VoidCallback, void, void*);

static void passCallback(VoidCallback callback, void* context) {
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

    passCallback(Cast(&callback, VoidCallback), &square);
}