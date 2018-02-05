#include <stdio.h>
#include <stdlib.h>

typedef struct fraction {
	long num;
	long den;
} fraction_t;


fraction_t frac_simplify(fraction_t a) {
	long x1, x2, gcd;
	fraction_t result;
	x1 = a.num;
	x2 = a.den;
	if (x1 < x2) {
		gcd = x1;
	} else {
		gcd = x2;
	}
	if (x1 == 0 || x2 == 0) {
		result.num = 0;
		result.den = 0;
	} else {
		while (gcd > 1) {
			if (x1 % gcd == 0 && x2 % gcd == 0)
				break;
			gcd--;
		}
		result.num = x1 / gcd;
		result.den = x2 / gcd;
	}
	return result;
}



fraction_t frac_new(long num, long den) {
	fraction_t f = {num, den};
	return f;
}






fraction_t frac_fromfloat(float a) {
	fraction_t f;
	long m = 1;
	while ((a * m)-(long)(a * m) > 0) {
		m *= 10;
	}
	f.num = (long)(a * m);
	f.den = m;
	return frac_simplify(f);
}




fraction_t frac_add(fraction_t a, fraction_t b) {
	fraction_t result;
	result.num = a.num * b.den + b.num * a.den;
	result.den = a.den * b.den;
	return frac_simplify(result);
}

fraction_t frac_mul(fraction_t a, fraction_t b) {
	fraction_t r;
	r.num = a.num * b.num;
	r.den = a.den * b.den;
	return frac_simplify(r);
}

fraction_t frac_div(fraction_t a, fraction_t b) {
	fraction_t r;
	r.num = a.num * b.den;
	r.den = a.den * b.num;
	return frac_simplify(r);
}

const char* frac_stringify(fraction_t a) {
	char *buffer = (char*)malloc(50 * sizeof(char));
	fraction_t f;
	f.num = a.num;
	f.den = a.den;
	f = frac_simplify(f);

	if (f.den != 1) {
		sprintf(buffer, "%ld/%ld", a.num, a.den);
	} else {
		sprintf(buffer, "%ld", a.num);
	}
	
	return buffer;
}

float frac_solve(fraction_t f) {
	return (float)f.num / (float)f.den;
}