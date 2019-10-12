#! /bin/sh

PROGRAM="bin/bauhaus"

# ------------------------------------------------------------------------------

die() {
    printf "FAIL: %s\n" $1
    exit 1
}

mem_test() {
    KEY="$1"
    VAL="$2"
    "$KEY"="$VAL" valgrind --leak-check=yes bin/bauhaus
}

# ------------------------------------------------------------------------------

# Assert that the program is present.
[ -x "$PROGRAM" ] || die "Program $PROGRAM does not exist / not executable."

# Assert that valgrind is present
command -v valgrind > /dev/null || die "Valgrind not found."

# ------------------------------------------------------------------------------

# Mem test when no env param is passed.
valgrind --leak-check=yes "$PROGRAM" || die "Test with no env vars failed."
NJOBS="0" valgrind --leak-check=yes "$PROGRAM" || die "Test with NJOBS=0 failed."
NJOBS="2" valgrind --leak-check=yes "$PROGRAM" || die "Test with NJOBS=2 failed."
EXITCODE="0" valgrind --leak-check=yes "$PROGRAM" || die "Test with EXITCODE=0 failed."
EXITCODE="6" valgrind --leak-check=yes "$PROGRAM" || die "Test with EXITCODE=6 failed."
