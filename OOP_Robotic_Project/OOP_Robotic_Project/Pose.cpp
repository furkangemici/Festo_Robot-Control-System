#include "Pose.h"
#include <cmath>
#include <iostream>
using namespace std;


Pose::Pose() : x(0), y(0), th(0) {}


Pose::Pose(double x, double y, double th) : x(x), y(y), th(th) {}


double Pose::getX() {
    return x;
}


void Pose::setX(double x) {
    if (!this) {
        throw std::runtime_error("Pose object is null!");
    }
    this->x = x;
}


double Pose::getY() {
    return y;
}


void Pose::setY(double y) {
    this->y = y;
}


double Pose::getTh() {
    return th;
}


void Pose::setTh(double th) {
    this->th = th;
}


bool Pose::operator==(const Pose& other) {
    return (x == other.x && y == other.y && th == other.th);
}


Pose Pose::operator+(const Pose& other) {
    return Pose(x + other.x, y + other.y, th + other.th);
}

Pose Pose::operator-(const Pose& other) {
    return Pose(x - other.x, y - other.y, th - other.th);
}


Pose& Pose::operator+=(const double& other) {
    x += other;
    y += other;
    th += other;
    return *this;
}


Pose& Pose::operator-=(const double& other) {
    x -= other;
    y -= other;
    th -= other;
    return *this;
}


bool Pose::operator<(const Pose& other) {
    if (x < other.x) return true;
    if (x == other.x && y < other.y) return true;
    if (x == other.x && y == other.y && th < other.th) return true;
    return false;
}


void Pose::getPose(double& _x, double& _y, double& _th) {
    _x = x;
    _y = y;
    _th = th;
}


void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}


double Pose::findDistanceTo(const Pose& pos) {
    double dx = pos.x - x;
    double dy = pos.y - y;
    double distance = sqrt(pow(dx, 2) + pow(dy, 2));
    return distance;
}


double Pose::findAngleTo(const Pose& pos) {
    double dx = pos.x - x;
    double dy = pos.y - y;
    double angle = atan2(dy, dx);
    return angle;
}
