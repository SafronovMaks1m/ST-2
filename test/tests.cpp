#include "circle.h"
#include "tasks.h"
#include <cmath>
#include <gtest/gtest.h>

TEST(Circle, ConstructorRadius) {
  Circle c(10.0);
  EXPECT_NEAR(10.0, c.getRadius(), 0.01);
}

TEST(Circle, ConstructorArea) {
  double r = 10.0;
  Circle c(r);
  double pi = acos(-1);
  EXPECT_NEAR(pi * r * r, c.getArea(), 0.01);
}

TEST(Circle, ConstructorFerence) {
  double r = 10.0;
  Circle c(r);
  double pi = acos(-1);
  EXPECT_NEAR(2 * pi * r, c.getFerence(), 0.01);
}

TEST(Circle, SetRadiusArea) {
  Circle c(1.0);
  c.setRadius(5.0);
  double pi = acos(-1);
  EXPECT_NEAR(pi * 25, c.getArea(), 0.01);
}

TEST(Circle, SetRadiusFerence) {
  Circle c(1.0);
  c.setRadius(2.0);
  double pi = acos(-1);
  EXPECT_NEAR(2 * pi * 2, c.getFerence(), 0.01);
}

TEST(Circle, SetFerenceRadius) {
  double pi = acos(-1);
  double f = 2 * pi * 10;

  Circle c(1.0);
  c.setFerence(f);

  EXPECT_NEAR(10.0, c.getRadius(), 0.01);
}

TEST(Circle, SetFerenceArea) {
  double pi = acos(-1);
  double f = 2 * pi * 2;

  Circle c(1.0);
  c.setFerence(f);

  EXPECT_NEAR(pi * 4, c.getArea(), 0.01);
}

TEST(Circle, SetAreaRadius) {
  double pi = acos(-1);
  double a = pi * 100;

  Circle c(1.0);
  c.setArea(a);

  EXPECT_NEAR(10.0, c.getRadius(), 0.01);
}

TEST(Circle, SetAreaFerence) {
  double pi = acos(-1);
  double a = pi * 25;

  Circle c(1.0);
  c.setArea(a);

  EXPECT_NEAR(2 * pi * 5, c.getFerence(), 0.01);
}

TEST(Circle, ZeroRadius) {
  Circle c(0.0);

  EXPECT_DOUBLE_EQ(0.0, c.getArea());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
}

TEST(Circle, SetAreaZero) {
  Circle c(10.0);
  c.setArea(0.0);

  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
}

TEST(Circle, RadiusAreaReversible) {
  Circle c(7.5);

  double area = c.getArea();
  c.setArea(area);

  EXPECT_NEAR(7.5, c.getRadius(), 0.01);
}

TEST(Circle, FerenceRadiusReversible) {
  Circle c(1.0);

  c.setFerence(100.0);
  double r = c.getRadius();

  c.setRadius(r);

  EXPECT_NEAR(100.0, c.getFerence(), 0.01);
}

TEST(Circle, SmallRadius) {
  Circle c(0.5);
  EXPECT_NEAR(0.5, c.getRadius(), 0.01);
}

TEST(Circle, LargeRadius) {
  Circle c(1000.0);
  EXPECT_NEAR(1000.0, c.getRadius(), 0.01);
}

TEST(Circle, AreaConsistency) {
  Circle c(4.0);
  double pi = acos(-1);

  EXPECT_NEAR(pi * 16, c.getArea(), 0.01);
}

TEST(Circle, FerenceConsistency) {
  Circle c(3.0);
  double pi = acos(-1);

  EXPECT_NEAR(2 * pi * 3, c.getFerence(), 0.01);
}

TEST(Circle, UpdateAfterMultipleChanges) {
  Circle c(2.0);
  c.setRadius(5.0);
  c.setArea(acos(-1) * 9);

  EXPECT_NEAR(3.0, c.getRadius(), 0.01);
}

TEST(EarthTask, GapFormula) {
  double pi = acos(-1);
  EXPECT_NEAR(1.0 / (2.0 * pi), earthRopeGap(), 0.0001);
}

TEST(PoolTask, TotalCost) {
  double pi = acos(-1);

  double area = pi * (4 * 4 - 3 * 3);
  double fence = 2 * pi * 4;

  double expected = area * 1000 + fence * 2000;

  EXPECT_NEAR(expected, poolTotalCost(), 0.1);
}