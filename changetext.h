
#if defined(WIN32) || defined(WINDOWS)
#include <windows.h>
#ifdef BUILD_DLL
   // the dll exports
   #define EXPORT __declspec(dllexport)
#else
   // the exe imports
   #define EXPORT __declspec(dllimport)
#endif
#else
   #define EXPORT extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

EXPORT int Init();
EXPORT uint16_t * ChangeText(uint16_t * src);

#ifdef __cplusplus
}
#endif
