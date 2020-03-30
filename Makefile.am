AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = lu

lu_SOURCES = src/lu.c src/version.c src/tohuman.c

lu_CFLAGS = -I ./include -std=c99 -Wall -Wextra -Wundef -Wunused -Wshadow -Wcast-align

TESTS = tests/basic.sh

EXTRA_DIST = tests

noinst_HEADERS = include/lu.h include/version.h include/tohuman.h

### man1_MANS = man/lu.1

dist_man_MANS = man/lu.1
