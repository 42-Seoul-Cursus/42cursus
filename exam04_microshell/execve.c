#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    execve("/bin/ls", (char *[]){"ls", "-a", NULL}, NULL);
    printf("FAIL\n");
    return 0;
}
