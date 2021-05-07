#ifndef GLOBALS_H
#define GLOBALS_H

#define YETTA_VERSION_MAJOR                         (0)
#define YETTA_VERSION_MINOR                         (1)
#define YETTA_VERSION_PATCH                         (0)

#define YETTA_VERSION_CHECK(major, minor, patch)    ((major<<16) | (minor<<8) | (patch))
#define YETTA_VERSION                               YETTA_VERSION_CHECK(YETTA_VERSION_MAJOR, YETTA_VERSION_MINOR, YETTA_VERSION_PATCH)

#endif // GLOBALS_H
