# C
## Prototypes of standard string functions
```C
#include <string.h>

char * strcpy ( char * destination, const char * source ); // returns destination
char * strncpy ( char * destination, const char * source, size_t num );

size_t strlen ( const char * str );

const char * strstr ( const char * haystack, const char * needle );
const char * strchr ( const char * str, int character );

int memcmp(const void* ptr1, const void* ptr2, size_t num);
void * memset ( void * ptr, int value, size_t num ); // value is stored in 'unsigned char'
```
