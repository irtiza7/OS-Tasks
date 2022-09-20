#include <unistd.h>

int execlp(
    const char *file,
    const char *arg0,
    const char *arg1,
    … const char *argn,
    NULL);
