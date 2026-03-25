
#include <stdio.h>
#include <stdbool.h>

#include "shapes.h"

int main(void) {

    // --- Test Points ---
    Point p1 = makePoint(0.0f, 0.0f);
    Point p2 = makePoint(3.0f, 4.0f);
    Point p3 = makePoint(6.0f, 0.0f);
    Point p4 = makePoint(3.0f, 4.0f);   // identical to p2

    printf("p1 = (%f, %f)\n", p1.x, p1.y);
    printf("p2 = (%f, %f)\n", p2.x, p2.y);
    printf("p3 = (%f, %f)\n", p3.x, p3.y);
    printf("p4 = (%f, %f)\n\n", p4.x, p4.y);

    // --- Test samePoint ---
    printf("samePoint(p2, p4) = %d (expected 1)\n", samePoint(p2, p4));
    printf("samePoint(p1, p2) = %d (expected 0)\n\n", samePoint(p1, p2));

    // --- Test Line ---
    Line L1 = makeLine(p1, p2);
    printf("Line L1: p1=(%f,%f), p2=(%f,%f)\n",
           L1.p[0].x, L1.p[0].y, L1.p[1].x, L1.p[1].y);

    printf("lineLength(L1) = %f (expected 5.0)\n\n", lineLength(L1));

    // --- Test pointInLine ---
    printf("pointInLine(p2, L1) = %d (expected 1)\n", pointInLine(p2, L1));
    printf("pointInLine(p3, L1) = %d (expected 0)\n\n", pointInLine(p3, L1));

    // --- Test Triangle ---
    Triangle T = makeTriangle(p1, p2, p3);
    printf("Triangle T: p1=(%f,%f), p2=(%f,%f), p3=(%f,%f)\n",
           T.p[0].x, T.p[0].y,
           T.p[1].x, T.p[1].y,
           T.p[2].x, T.p[2].y);

    printf("triangleArea(T) = %f (expected 12.0)\n\n", triangleArea(T));

    // --- Test pointInTriangle ---
    printf("pointInTriangle(p1, T) = %d (expected 1)\n", pointInTriangle(p1, T));
    printf("pointInTriangle(p4, T) = %d (expected 1)\n", pointInTriangle(p4, T));
    printf("pointInTriangle(makePoint(2,2), T) = %d (expected 0)\n\n",
           pointInTriangle(makePoint(2,2), T));

    return 0;
}
