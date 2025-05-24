#include <stdio.h>
#include <stdlib.h>

#include "args.h"

int main(int argc, char *argv[]) {
	printf("Sum: %d", arg_sum(5, 1, 2, 3, 4, 5));
	printf("\nMax: %d", arg_max(5, 1, 2, 3, 4, 5));
	printf("\nMin: %d", arg_min(5, 1, 2, 3, 4, 5));
	printf("\nAvg: %d", arg_avg(5, 1, 2, 3, 4, 5));
}
