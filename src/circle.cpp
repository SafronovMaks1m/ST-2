// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>
#include <cstdint>

Circle::Circle(double r) { setRadius(r); }

void Circle::setRadius(double r) {
  radius = r;
  double pi = acos(-1);
  ference = 2 * pi * radius;
  area = pi * radius * radius;
}

void Circle::setFerence(double f) {
  ference = f;
  double pi = acos(-1);
  radius = ference / (2 * pi);
  area = pi * radius * radius;
}

void Circle::setArea(double a) {
  area = a;
  double pi = acos(-1);
  radius = sqrt(area / pi);
  ference = 2 * pi * radius;
}

double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }
