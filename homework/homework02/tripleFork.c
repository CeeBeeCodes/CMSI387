#include <unistd.h>

int main(int argc, char** argv)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        fork();
    }
    sleep(30);
}