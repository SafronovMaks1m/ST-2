// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

double earthRopeGap() {
  double radius_earth = 6378100;
  Circle earth(radius_earth);
  earth.setFerence(earth.getFerence() + 1.0);
  return earth.getRadius() - radius_earth;
}

double poolTotalCost() {
  double radius_pool = 3;
  double width_concrete_path = 1;

  Circle pool(radius_pool);
  Circle total(radius_pool + width_concrete_path);

  double path_area = total.getArea() - pool.getArea();
  double concrete_cost = path_area * 1000;

  double fence_cost = total.getFerence() * 2000;

  return concrete_cost + fence_cost;
}
