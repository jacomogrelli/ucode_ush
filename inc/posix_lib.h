#ifndef POSIX_LIB_H
#define POSIX_LIB_H

//------ POSIX C lib------
#include <aio.h>         // Asynchronous input and output
#include <arpa/inet.h>   // Functions for manipulating numeric IP addresses (part of Berkeley sockets)
#include <assert.h>      // Verify assumptions
#include <complex.h>     // Complex Arithmetic, see C mathematical functions
#include <cpio.h>        // Magic numbers for the cpio archive format
#include <ctype.h>       // Character types
#include <dirent.h>      // Allows the opening and listing of directories
#include <dlfcn.h>       // Dynamic linking
#include <errno.h>       // Retrieving Error Number
#include <fcntl.h>       // File opening, locking and other operations
#include <fenv.h>        // Floating-Point Environment (FPE), see C mathematical functions
#include <float.h>       // Floating-point types, see C data types
#include <fmtmsg.h>      // Message display structures
#include <fnmatch.h>     // Filename matching
#include <ftw.h>         // File tree traversal
#include <glob.h>        // Pathname "globbing" (pattern-matching)
#include <grp.h>         // User group information and control
#include <iconv.h>       // Codeset conversion facility
#include <inttypes.h>    // Fixed sized integer types, see C data types
#include <iso646.h>      // Alternative spellings, see C alternative tokens
#include <langinfo.h>    // Language information constants – builds on C localization functions
#include <libgen.h>      // Pathname manipulation
#include <limits.h>      // Implementation-defined constants, see C data types
#include <locale.h>      // Category macros, see C localization functions
#include <math.h>        // Mathematical declarations, see C mathematical functions
#include <monetary.h>    // String formatting of monetary units
//#include <mqueue.h>      // Message queue
#include <ndbm.h>        // NDBM database operations
#include <net/if.h>      // Listing of local network interfaces
#include <netdb.h>       // Translating protocol and host names into numeric addresses (part of Berkeley sockets)
#include <netinet/in.h>  // Defines Internet protocol and address family (part of Berkeley sockets)
#include <netinet/tcp.h> // Additional TCP control options (part of Berkeley sockets)
#include <nl_types.h>    // Localization message catalog functions
#include <poll.h>        // Asynchronous file descriptor multiplexing
#include <pthread.h>     // Defines an API for creating and manipulating POSIX threads
#include <pwd.h>         // passwd (user information) access and control
#include <regex.h>       // Regular expression matching
#include <sched.h>       // Execution scheduling
#include <search.h>      // Search tables
#include <semaphore.h>   // POSIX semaphores
#include <setjmp.h>      // Stack environment declarations
#include <signal.h>      // Signals, see C signal handling
#include <spawn.h>       // Process spawning
#include <stdarg.h>      // Handle Variable Argument List
#include <stdbool.h>     // Boolean type and values, see C data types
#include <stddef.h>      // Standard type definitions, see C data types
#include <stdint.h>      // Integer types, see C data types
#include <stdio.h>       // Standard buffered input/output, see C file input/output
#include <stdlib.h>      // Standard library definitions, see C standard library
#include <string.h>      // Several String Operations, see C string handling
#include <strings.h>     // Case-insensitive string comparisons
//#include <stropts.h>     // Stream manipulation, including ioctl
#include <sys/ipc.h>     // Inter-process communication (IPC)
#include <sys/mman.h>    // Memory management, including POSIX shared memory and memory mapped files
#include <sys/msg.h>     // POSIX message queues
#include <sys/resource.h>// Resource usage, priorities, and limiting
#include <sys/select.h>  // Synchronous I/O multiplexing
#include <sys/sem.h>     // XSI (SysV style) semaphores
#include <sys/shm.h>     // XSI (SysV style) shared memory
#include <sys/socket.h>  // Main Berkeley sockets header
#include <sys/stat.h>    // File information (stat et al.)
#include <sys/statvfs.h> // File System information
#include <sys/time.h>    // Time and date functions and structures
#include <sys/times.h>   // File access and modification times
#include <sys/types.h>   // Various data types used elsewhere
#include <sys/uio.h>     // Vectored I/O operations
#include <sys/un.h>      // Unix domain sockets
#include <sys/utsname.h> // Operating system information, including uname
#include <sys/wait.h>    // Status of terminated child processes (see wait)
#include <syslog.h>      // System error logging
#include <tar.h>         // Magic numbers for the tar archive format
#include <termios.h>     // Allows terminal I/O interfaces
#include <tgmath.h>      // Type-Generic Macros, see C mathematical functions
#include <time.h>        // Type-Generic Macros, see C date and time functions
//#include <trace.h>       // Tracing of runtime behavior (DEPRECATED)
#include <ulimit.h>      // Resource limiting (DEPRECATED in favor of <sys/resource.h>)
#include <unistd.h>      // Various essential POSIX functions and constants
#include <utime.h>       // inode access and modification times
#include <utmpx.h>       // User accounting database functions
#include <wchar.h>       // Wide-Character Handling, see C string handling
#include <wctype.h>      // Wide-Character Classification and Mapping Utilities, see C character classification
#include <wordexp.h>     // Word-expansion like the shell would perform
#include <malloc/malloc.h>


#endif
