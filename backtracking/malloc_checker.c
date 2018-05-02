#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

unsigned long count = 0;

void* malloc(size_t sz)
{
    void *(*libc_malloc)(size_t) = dlsym(RTLD_NEXT, "malloc");
    printf("malloc %lu\n", ++count);
    return libc_malloc(sz);
}

void free(void *p)
{
    void (*libc_free)(void*) = dlsym(RTLD_NEXT, "free");
    printf("free %lu\n", --count);
    libc_free(p);
}

int main()
{
    free(malloc(10));
	malloc(10);
    return 0;
}
