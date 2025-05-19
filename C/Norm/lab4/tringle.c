#include <math.h>
#include <stdbool.h>

bool tringleExists(double a, double b, double c) {
	return ((a + b) > c && (b + c) > a && (a + c) > b);
}

int Pmath(double a, double b, double c) {
	return a + b + c;
}

int Smath(double a, double b, double c, double p) {
	return sqrt(p * (p - a) * (p - b) * (p - c));
}