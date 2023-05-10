#include "main.h"

int main(int argc, char **argv)
{
    char *const args[] = {"/bin/ls", "-l", NULL};
    execv(args[0], args);
    return 0;
}