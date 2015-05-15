#ifndef PIXMAN_WIN32_TLS_PRIVATE_H
#define PIXMAN_WIN32_TLS_PRIVATE_H

#if defined(__MINGW32__) || (defined(_MSC_VER) && _WIN32_WINNT < 0x0600)

void _pixman_win32_tls_create (unsigned *index, volatile int *initialized);

#endif

#endif
