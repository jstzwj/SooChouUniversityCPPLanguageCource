#pragma once
#ifndef MT_VERSION
#define MT_VERSION

/*
** Ensure these symbols were not defined by some previous header file.
*/
#ifdef VERSION
# undef VERSION
#endif

#define VERSION "1.0.0"
#define MAJOR_VERSION 1
#define MINOR_VERSION 0

#endif // !MT_VERSION
