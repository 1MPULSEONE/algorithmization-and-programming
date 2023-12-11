#include <cmath>
#include <iomanip>
#include <iostream>

double checkSquare(double x, double a) { 
    return x * x - x + std::sqrt(x) - a;
}

double findByBinarySearch(double a) {
  double left = 0;
  double right = 1000000;

  double epsilon = 1e-7;
  while (right - left > epsilon) {
    double mid = (left + right) / 2;
    if (checkSquare(left, a) * checkSquare(mid, a) <= 0) {
      right = mid;
    } else {
      left = mid;
    }
  }

  return (left + right) / 2;
}

int main() {

  double a;
  scanf("%lf", &a);
  double root = findByBinarySearch(a);
  std::cout << std::setprecision(7);
  std::cout << root <<  std::endl;

  return 0;
}