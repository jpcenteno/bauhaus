#include <stdlib.h>
#include <string.h>

#include "jobs.h"

static const char* icon = "⏾";

#define JOBS_BUF_SIZE 16
static char buf[JOBS_BUF_SIZE] = {0};

char* jobs(const void* ignored) {

    char* njobs = getenv("NJOBS");

    if ( strcmp(njobs, "0") == 0 ) return NULL;

    strncpy(buf, icon, sizeof(buf) - 1);
    strncpy(buf + strlen(icon), njobs, sizeof(buf) - 1);

    return buf;
}
