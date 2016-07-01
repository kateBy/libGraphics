
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

#include <string>
#include <cstring>

EXPORT int Init();
EXPORT uint16_t * ChangeText(uint16_t * src);
EXPORT std::string ChangeTextString(std::string src_text);
size_t my_strlen(uint16_t * s);
size_t my_strlen16(uint16_t * s);
