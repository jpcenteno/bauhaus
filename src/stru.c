#include "stru.h"

char* stru_copy_to_heap(const char* s) {
    size_t len = strlen(s);
    char* out = malloc(len + 1);
    strcpy(out, s);
    return out;
}

int stru_is_prefix(const char* pre, const char* s) {
    size_t len_pre = strlen(pre);
    size_t len_s = strlen(s);
    return ( len_pre <= len_s ) && ( memcmp(pre, s, len_pre) == 0 );
}

char* stru_replace_prefix(char* s, const char* oldpre, const char* newpre) {

    if (! stru_is_prefix(oldpre, s)) return s;

    size_t len_new = strlen(s) - strlen(oldpre) + strlen(newpre);
    char* new = malloc( len_new + 1);

    strcpy(new, newpre);
    strcpy(new + strlen(newpre), s + strlen(oldpre));
    new[len_new] = 0;

    free(s);
    return new;

}
