
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
size_t my_strlen(uint16_t * s);
size_t my_strlen16(uint16_t * s);

#ifdef __cplusplus
}
#endif
