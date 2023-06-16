#include "circle.h"


Circle::Circle(float _x, float _y, int _radius) {
    x = _x;
    y = _y;
    radius = _radius;
    dx = 0;
    dy = 0;
}

void Circle::physStep(double dt) {
    dx += ddx * dt;
    dy += ddy * dt;
    x += dx * dt;
    y += dy * dt;
}

void Circle::setRadius(int r) {
    if (r > 0) radius = r;
}

int Circle::getRadius() {
    return radius;
}

float Circle::getPosX() {
    return x;
}

float Circle::getPosY() {
    return y;
}

float Circle::getVelX() {
    return dx;
}

float Circle::getVelY() {
    return dy;
}

void Circle::setVelX(float _dx) {
    dx = _dx;
}

void Circle::setVelY(float _dy) {
    dy = _dy;
}

float Circle::getAccX() {
    return ddx;
}

float Circle::getAccY() {
    return ddy;
}

void Circle::setAccX(float _ddx) {
    ddx = _ddx;
}

void Circle::setAccY(float _ddy) {
    ddy = _ddy;
}

void Circle::setVel(float _dx, float _dy) {
    Circle::setVelX(_dx);
    Circle::setVelY(_dy);
}
