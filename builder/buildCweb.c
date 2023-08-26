#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *command = "./build.sh";
    char buffer[128];
    FILE *fp = popen(command, "r");

    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    pclose(fp);

    return 0;
}
