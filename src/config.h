#ifndef __CONFIG_H
#define __CONFIG_H value

#include <stddef.h>

#include "types.h"

#include "blocks/pwd.h"
#include "blocks/jobs.h"
#include "blocks/exitcode.h"

/** Custom Colors ----------------------------------------------------------- */

// Pallete
const COLOR_T color_red = 0xef2f27;
const COLOR_T color_black = 0x000000;
const COLOR_T color_white = 0xffffff;

// Colors to use
const COLOR_T color_bg = color_red;
const COLOR_T color_fg = color_white;
const COLOR_T color_bg_reset = color_black;
const COLOR_T color_fg_reset = color_white;

/** Prompt blocks ----------------------------------------------------------- */

block_t blocks[] = {
    { pwd, NULL },
    { jobs, NULL },
    { exitcode, NULL },
};

#endif /* ifndef __CONFIG_H */
