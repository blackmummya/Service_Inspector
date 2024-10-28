#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
    FILE *fp, *fp2, *fp3, *fp4;
    char buffer[1024], buffer2[1024], buffer3[1024], buffer4[1024];
    char servicename[128], command[256], command2[256], command3[256], command4[256];
    char PID[128] = "";

    printf("[+] Enter Service Name: ");
    scanf("%127s", servicename);

    sprintf(command, "sc qc %s", servicename);
    sprintf(command2, "sc query %s", servicename);
    sprintf(command3, "sc queryex %s", servicename);

    fp = popen(command, "r");
    fp2 = popen(command2, "r");
    fp3 = popen(command3, "r");

    if (!fp || !fp2 || !fp3) {
        printf("ERROR: Failed to run one or more commands\n");
        return 1;
    }

    printf("\n[+] Filtering service configuration information\n");
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, "SERVICE_NAME") || strstr(buffer, "TYPE") || strstr(buffer, "START_TYPE") ||
            strstr(buffer, "ERROR_CONTROL") || strstr(buffer, "BINARY_PATH_NAME") || 
            strstr(buffer, "DISPLAY_NAME") || strstr(buffer, "DEPENDENCIES") || 
            strstr(buffer, "SERVICE_START_NAME")) 
        {
            printf("%s", buffer);
        }
    }

    while (fgets(buffer2, sizeof(buffer2), fp2)) {
        if (strstr(buffer2, "STATE")) {
            printf("%s", buffer2);
        }
    }

    while (fgets(buffer3, sizeof(buffer3), fp3)) {
        if (strstr(buffer3, "PID")) {
            sscanf(buffer3, "PID : %127s", PID);
        }
    }

    if (strlen(PID) > 1) {
        sprintf(command4, "netstat -ano | findstr %s", PID);
        fp4 = popen(command4, "r");

        if (!fp4) {
            printf("ERROR: Failed to run netstat command\n");
            return 1;
        }

        while (fgets(buffer4, sizeof(buffer4), fp4)) {
            printf("%s", buffer4);
        }

        pclose(fp4);
    } else {
        printf("The %s service currently has no open network connections.\n", servicename);
    }

    pclose(fp);
    pclose(fp2);
    pclose(fp3);

    return 0;
}
