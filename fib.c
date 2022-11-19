#include <stdint.h>
#include <stdio.h>
#include <gmp.h>

void helper(mpz_t res,size_t n, mpz_t a, mpz_t b)
{
    if (n == 0)
    {
        mpz_set(res, a);
        return;
    }
    if (n == 1)
    {
        mpz_set(res, b);
        return;
    }
    mpz_add(a, a, b);
    return helper(res, n-1, b, a);
}
void fib(mpz_t res, size_t n)
{
    mpz_t a,b;
    mpz_inits(a,b,NULL);
    mpz_set_ui(a, 1);
    mpz_set_ui(b, 1);
    helper(res, n, a, b);
    mpz_clears(a,b,NULL);
}

int main()
{
    mpz_t res;
    mpz_init(res);

    for (int i = 0; i < 100000; i++)
    {
        fib(res, i);
    }
    mpz_clear(res);
    return 0;
}
