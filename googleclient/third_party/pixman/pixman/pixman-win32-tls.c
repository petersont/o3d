#if defined(__MINGW32__) || (defined(_MSC_VER) && _WIN32_WINNT < 0x0600)

#include "pixman-win32-tls.h"

#include <stdlib.h>
#include <windows.h>

#include "pixman-compiler.h"
#include "pixman-win32-tls-private.h"

struct tls_entry {
  DWORD *index;
  volatile int *initialized;
  struct tls_entry *next;
};

static struct tls_entry *tls_entries = NULL;
static HANDLE win32_tls_mutex = NULL;

static void tls_register (unsigned *index, volatile int *initialized) {
  struct tls_entry *entry = malloc (sizeof(struct tls_entry));
  if (entry != NULL) {
    entry->index = index;
    entry->initialized = initialized;
    entry->next = tls_entries;
    tls_entries = entry;
  }
}

void _pixman_win32_tls_create (unsigned *index, volatile int *initialized) {
  if (win32_tls_mutex == NULL) {
    HANDLE mutex = CreateMutex (NULL, 0, NULL);
    if (InterlockedCompareExchangePointer (&win32_tls_mutex, mutex, NULL)
        != NULL) {
      CloseHandle (mutex);
    }
  }
  WaitForSingleObject (win32_tls_mutex, INFINITE);
  if (!(*initialized)) {
    *index = TlsAlloc ();
    tls_register (index, initialized);
    *initialized = 1;
  }
  ReleaseMutex (win32_tls_mutex);
}

PIXMAN_EXPORT void pixman_win32_tls_shutdown_thread (void) {
  struct tls_entry *entry = tls_entries;
  while (entry != NULL) {
    struct tls_entry *next = entry->next;
    DWORD index = *entry->index;
    void *data = TlsGetValue (index);
    if (data != NULL) {
      TlsSetValue (index, NULL);
      free (data);
    }
    entry = next;
  }
}

PIXMAN_EXPORT void pixman_win32_tls_shutdown (void) {
  struct tls_entry *entry = tls_entries;
  pixman_win32_tls_shutdown_thread ();
  while (entry != NULL) {
    struct tls_entry *next = entry->next;
    DWORD index = *entry->index;
    TlsFree (index);
    entry->initialized = 0;
    free (entry);
    entry = next;
  }
  tls_entries = NULL;
  CloseHandle (win32_tls_mutex);
  win32_tls_mutex = NULL;
}

#elif defined(_MSC_VER)

PIXMAN_EXPORT void pixman_win32_tls_shutdown_thread (void) {
}

PIXMAN_EXPORT void pixman_win32_tls_shutdown (void) {
}

#endif
