#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

/* Function declarations ---------------------------------------------------- */

static void print_block(const block_t);
/* static void set_bg_color(const COLOR_T); */
static void reset_terminal_color();

#define LENGHT(X) (sizeof X / sizeof X[0])

/* Config Loading ----------------------------------------------------------- */

#include "config.h"

/* Function definitions  ---------------------------------------------------- */

int main(int argc, char *argv[]) {
    for (size_t i = 0; i < LENGHT(blocks); ++i) {
        print_block(blocks[i]);
    }
    printf("\n> ");
    return 0;
}

static void print_block(const block_t block) {

    char* msg = block.func(block.arg);
    if ( msg ) {

        /* set_bg_color(color_bg); */
        printf("\\[\\e[41m\\]");
        printf(" %s ", msg);
        reset_terminal_color();

    }

}

// static void set_bg_color(const COLOR_T c) {
//     uint8_t r = ( c >> 16 ) & 0xFF;
//     uint8_t g = ( c >> 8 ) & 0xFF;
//     uint8_t b = c & 0xFF;
//     printf("\\[\\e[48;2;%d;%d;%dm\\]", r, g, b);
// }

static void reset_terminal_color() {
    printf("\\[\\e[0m\\]");
}
