#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
    return (complex_t) {
        .real = a.real + b.real,
        .imag = a.imag + b.imag
    };
}

complex_t c_sub(complex_t a, complex_t b)
{
    return (complex_t) {
        .real = a.real - b.real,
        .imag = a.imag - b.imag
    };
}

complex_t c_mul(complex_t a, complex_t b)
{
    return (complex_t) {
        .real = a.real * b.real - a.imag * b.imag,
        .imag = a.imag * b.real + a.real * b.imag
    };
}

complex_t c_div(complex_t a, complex_t b)
{
    double rec_b_sqr = 1 / (b.real * b.real + b.imag * b.imag);

    return (complex_t) {
        .real = (a.real * b.real + a.imag * b.imag) * rec_b_sqr,
        .imag = (a.imag * b.real - a.real * b.imag) * rec_b_sqr
    };
}

double c_abs(complex_t x)
{
    return sqrt(x.real * x.real + x.imag * x.imag);
}

complex_t c_conjugate(complex_t x)
{
    return (complex_t) {
        .real = x.real,
        .imag = -x.imag
    };
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    double e_a = exp(x.real);

    return (complex_t) {
        .real = e_a * cos(x.imag),
        .imag = e_a * sin(x.imag)
    };
}
