#include <stdlib.h>
#include <string.h>

#include "exitcode.h"

static const char* icon = "!";

#define EXITCODE_BUF_SIZE 8
static char buf[EXITCODE_BUF_SIZE] = {0};

char* exitcode(const void* ignored) {

    const char* exitcode = getenv("EXITCODE");
    if ( (!exitcode) || (strcmp(exitcode, "0") == 0) ) return NULL;

    strncpy(buf, icon, sizeof(buf) - 1);
    strncpy(buf + strlen(icon), exitcode, sizeof(buf) - 1);

    return buf;
}
