#ifndef __STRU_H
#define __STRU_H

#include <stdlib.h>
#include <string.h>

/** Copy the string to a new position on the heap. */
char* stru_copy_to_heap(const char* s);

/** Returns true if `pre` is prefix of `s` */
int stru_is_prefix(const char* pre, const char* s);

/** Replace the old prefix with a new one iff it prefixes the stirng */
char* stru_replace_prefix(char* s, const char* oldpre, const char* newpre);

#endif /* ifndef __STRU_H */
