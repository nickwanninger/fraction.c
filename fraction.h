#ifndef __FRACTION__
#define __FRACTION__

typedef struct fraction_s {
	long num;
	long den;
} fraction_t;


fraction_t frac_simplify(fraction_t a);
fraction_t frac_new(long num, long den);
fraction_t frac_fromfloat(float a);
fraction_t frac_add(fraction_t a, fraction_t b);
fraction_t frac_sub(fraction_t a, fraction_t b);
fraction_t frac_mul(fraction_t a, fraction_t b);
fraction_t frac_div(fraction_t a, fraction_t b);
char* frac_stringify(fraction_t a);
float frac_solve(fraction_t f);

#include "fraction.c"

#endif