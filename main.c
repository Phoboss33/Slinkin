#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct passwd *pw;
    struct group *gr;

    if (argc != 2) {
        //printf(stderr, "Usage: %s username\n", argv[0]);
        //exit(EXIT_FAILURE);
    }

    pw = getpwnam(argv[1]);
    if (pw == NULL) {
        perror("getpwnam");
        //exit(EXIT_FAILURE);
    }

    //printf("Groups for user %s:\n", pw->pw_name);
    setgrent();
    while ((gr = getgrent()) != NULL) {
        for (int i = 0; gr->gr_mem[i] != NULL; i++) {
            if (strcmp(gr->gr_mem[i], pw->pw_name) == 0) {
                printf("  %s\n", gr->gr_name);
            }
        }
    }

    endgrent();
    return EXIT_SUCCESS;
}
