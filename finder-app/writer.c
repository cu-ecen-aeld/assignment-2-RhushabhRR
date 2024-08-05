#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    bool error = false;

    if (argc == 3)
    {
        int fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 00777);
        syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

        if (fd != -1)
        {
            int bytesWritten = write(fd, argv[2], strlen(argv[2]));
        }
        else
        {
            error = true;
            printf("%s could not be created", argv[1]);
            syslog(LOG_ERR, "%s could not be created", argv[1]);
        }
    }
    else
    {
        printf("Incorrect arguments. Please specify the arguments [FULL_PATH], [WRITESTR]");
        syslog(LOG_ERR, "Incorrect arguments. Please specify the arguments [FULL_PATH], [WRITESTR]");
        error = true;
    }

    return error;
}