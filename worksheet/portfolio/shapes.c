
#include <stdbool.h>
#include <math.h>

#include "shapes.h"

Point makePoint( float x, float y ) {
    Point new;
    // implementation
    new.x = x;
    new.y = y;
    return new;
}

// complete other functions below
// - start with stubs as above
// - compile regularly to test syntax
// - test functions by calling them from main()

Line makeLine(Point p1, Point p2) {
    Line new;
    // implementation
    new.p[0] = p1;
    new.p[1] = p2;
    return new;
}

Triangle makeTriangle(Point p1, Point p2, Point p3) {
    Triangle new;
    new.p[0] = p1;
    new.p[1] = p2;
    new.p[2] = p3;
    return new;
}

float lineLength(Line l) {
    // lineLength = sqrt(dx^2 + dy^2)
    float dx = l.p[1].x - l.p[0].x;
    float dy = l.p[1].y - l.p[0].y;
    float result = sqrtf(dx*dx + dy*dy);
    return result;
}

float triangleArea(Triangle t) {
    // triangleArea = 1/2 * ab * sinC
    float a = lineLength(makeLine(t.p[0], t.p[1]));
    float b = lineLength(makeLine(t.p[1], t.p[2]));
    float c = lineLength(makeLine(t.p[2], t.p[0]));
    // cosC = (a^2 + b^2 - c^2) / (2ab)
    float cosC = (a*a + b*b - c*c) / (2*a*b);
    // sinC = sqrt(1 - cosC^2)
    float sinC = sqrtf(1 - cosC*cosC);
    float result = 0.5 * a * b * sinC;
    return result;
}

bool samePoint(Point p1, Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    if(dx == 0 && dy == 0) {
        return true;
    } else {
        return false;
    }
}

bool pointInLine(Point p, Line l) {
    if(samePoint(p, l.p[0]) || samePoint(p, l.p[1])) {
        return true;
    } else {
        return false;
    }
}

bool pointInTriangle(Point p, Triangle t) {
    if(samePoint(p, t.p[0]) || samePoint(p, t.p[1]) || samePoint(p, t.p[2])) {
        return true;
    } else {
        return false;
    }
}