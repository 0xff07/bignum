#include <stdio.h>
#include <stdlib.h>

#include "bn.h"
#include "fibonacci.h"

int main(int argc, char *argv[])
{
    bn_t fib = BN_INITIALIZER;

    if (argc < 2)
        return -1;

    unsigned int n = strtoul(argv[1], NULL, 10);
    if (!n)
        return -2;

    fibonacci(n, fib);
    printf("Fib(%u)=", n), bn_print_dec(fib), printf("\n");

#define BUFLEN 4096
    char buf[BUFLEN];
    printf("Fib(%u)=", n);
    bn_snprint(fib, 10, buf, BUFLEN);
    printf("%s\n", buf);
 
    bn_free(fib);

    return 0;
}
