#include <stdlib.h> 
#include <unistd.h> 
#include <stdio.h> 
// #include <crack.h>
#define DICTIONARY "/usr/lib/cracklib_dict" 

int main(int argc, char *argv[]) {

    char *password; 
    char *problem; 
    int status = 0;
    
    printf("\nEnter an empty password or Ctrl-D to quit.\n");
    
    while ((password = getpass("\nPassword: ")) != NULL && *password ) { 
        if ((problem = FascistCheck(password, DICTIONARY)) != NULL) {
            printf("Bad password: %s.\n", problem); status = 1;
        } else {
            printf("Good password!\n");
        }
    }
    exit(status);
}
