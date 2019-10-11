#ifndef __CLI_H
#define __CLI_H

#include <stdint.h>

typedef struct cli_args_t {
    uint32_t n_jobs;
    int32_t exit_status;
} cli_args_t;

void cli_init(void);

uint32_t cli_get_n_jobs(void);

#endif /* ifndef __CLI_H */
