#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "pwd.h"


#define LEN_PWD_BUF 512
static char buf[LEN_PWD_BUF] = {0};


static bool is_prefix(const char* str, const char* pre);
static void remove_home_prefix(char* str, const char* home);


char* pwd(const void* arg) {

    strncpy(buf, getenv("PWD"), sizeof(buf) - 1);

    // Change home dir to '~'
    const char* home = getenv("HOME");
    if ( is_prefix(buf, home) ) {
        remove_home_prefix(buf, home);
    }

    return buf;
}


static bool is_prefix(const char* str, const char* pre) {
    return strncmp(pre, str, strlen(pre)) == 0;
}


static void remove_home_prefix(char* str, const char* home) {
    str[0] = '~';
    size_t home_len = strlen(home);
    memmove(str + 1, str + home_len, LEN_PWD_BUF - home_len);
}
