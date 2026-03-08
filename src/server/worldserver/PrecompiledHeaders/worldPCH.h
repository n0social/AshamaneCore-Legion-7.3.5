// OpenSSL must be included BEFORE any headers that define snprintf/vsnprintf macros
// (including Common.h which defines #define snprintf _snprintf on MSVC).
// This ensures CRYPTO_RWLOCK is typedef'd before any macro interference.
#include <openssl/crypto.h>
#include "Common.h"
#include "World.h"
#include "Log.h"
#include "Database/DatabaseEnv.h"
#include "Configuration/Config.h"
#include "Util.h"
