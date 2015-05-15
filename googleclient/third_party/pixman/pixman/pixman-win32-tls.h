#ifndef PIXMAN_WIN32_TLS_H
#define PIXMAN_WIN32_TLS_H

#if defined(__MINGW32__) || defined(_MSC_VER)

#ifdef  __cplusplus
extern "C" {
#endif

void pixman_win32_tls_shutdown_thread (void);
void pixman_win32_tls_shutdown (void);

#ifdef  __cplusplus
}
#endif

#endif

#endif
