#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

// Lets you recompile your program so that all the debug log messages are 
// removed. If you compile with NDEBUG defined, then "no debug" messages will
// remain.  The alternative translates any use of debug("format", arg1, arg2)
// into an fprintf call to stderr.  The magic here is the use of ##__VA_ARGS__
// which says "put whatever they had for extra arguments (...) here". Also
// notice the use of __FILE__ and __LINE__ to get the current file:line for
// the debug message. Very helpful.
#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

// Macro that's used in the others to get a safe readable version of errno.
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

// Check will make sure the condition A is true, and if not logs the error M
// (with variable arguments for log_err), then jumps to the function's error:
// for cleanup.
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// Sentinel is placed in any part of a function that shouldn't run, and if it
// does prints an error message then jumps to the error: label.  You put this
// in if-statements and switch-statements to catch conditions that shouldn't
// happen, like the default:.
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// Makes sure a pointer is valid, and if it isn't reports it as an error with
// "Out of memory"
#define check_mem(A) check((A), "Out of memory.")

// An alternative to check that this checks and handles an error, but if the
// error is common then you don't want to bother reporting it.  In this one
// it will use debug instead of log_err to report the message, so when you
// define NDEBUG the check still happens, the error jump goes off, but the
// message isn't printed.
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno; goto error; }

#endif
