#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


//==============================================================================
//
// Definitions
//
//==============================================================================

//--------------------------------------
//--------------------------------------

// The number of times each benchmark should be run.
#define MALLOC_ITER 10000000

// The number of bytes to allocate with the malloc benchmark.
#define MALLOC_SIZE 50


//==============================================================================
//
// Benchmarks
//
//==============================================================================

int64_t gettimems()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec*1000) + (tv.tv_usec/1000);
}

void print_elapsed(char *name, int64_t t0)
{
    int64_t t1 = gettimems();
    int64_t elapsed = t1-t0;
    float sec = ((float)(elapsed))/1000;
    printf("[%s]: %.3fs (%d iter/sec)\n", name, sec, (int)(MALLOC_ITER/sec));
}

void bench_malloc()
{
    int64_t t0 = gettimems();
    int i;
    for(i=0; i<MALLOC_ITER; i++) {
        void *ptr = malloc(MALLOC_SIZE);
        free(ptr);
    }

    print_elapsed("malloc", t0);
}


//==============================================================================
//
// Main
//
//==============================================================================

int main()
{
    bench_malloc();
    return 0;
}

