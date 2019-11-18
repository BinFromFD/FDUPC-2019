#ifndef TESTLIB_H
#define TESTLIB_H

#include <cstring>
#include <iostream>

#define ASSERT(c, msg) \
do { \
	if (!(c)) { \
		std::cerr << "ASSERT Failed : " << (msg) << std::endl; \
		while (1) ; \
	} \
} while(0)

#define ascanf(format, args...) ASSERT(scanf(format, args) != -1, "Input "#args)

static int line_cnt = 1;

#define Eoln() \
do { \
	char __ch__ = getchar(); \
	line_cnt ++; \
	ASSERT(__ch__ == '\n', "Eoln at line " + std::to_string(line_cnt)); \
} while(0)

#define Blank() \
do { \
	char __ch__ = getchar(); \
	ASSERT(__ch__ == ' ', "Blank at line " + std::to_string(line_cnt)); \
} while(0)

#define Eof() \
do { \
	char __ch__ = getchar(); \
	if (__ch__ == '\n') __ch__ = getchar(); \
	ASSERT(__ch__ == EOF, "Eof at line " + std::to_string(line_cnt)); \
} while(0)

#define CheckRange(n, l, r) ASSERT((l) <= (n) && (n) <= (r), "Range of "#n" at line " + std::to_string(line_cnt))

#endif
