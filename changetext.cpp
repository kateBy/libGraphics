#include "Python.h"
#include "changetext.hpp"
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include "basics.h"

#if defined(WIN32) || defined(WINDOWS)
#define ERROR_MESSAGE(message) MessageBox(0,message,"ChangeText",MB_ICONERROR)
#else
#define ERROR_MESSAGE(message) fputs(message, stderr)
#endif

PyObject * pModule = NULL,
         * pfuncChangeText = NULL,
         * pArgs = NULL;

static int initialized = 0;

EXPORT int Init() {
    Py_Initialize();
    #if defined(WIN32) || defined(WINDOWS)
    PyRun_SimpleString("import sys\nsys.stderr = open('changetext.err', 'a', 1, encoding='utf-8')\nsys.stdout = open('changetext.log', 'a', 1, encoding='utf-8')");
    #endif
    pModule = PyImport_ImportModule("changetext");
    if(pModule) {
        pfuncChangeText = PyObject_GetAttrString(pModule, "ChangeText");
        if(!(pfuncChangeText && PyCallable_Check(pfuncChangeText))) {
            Py_XDECREF(pfuncChangeText);
            pfuncChangeText = NULL;
            ERROR_MESSAGE("Error: Probably changetext.py module doesn't contain ChangeText function.\n");
        }
        else pArgs = PyTuple_New(1);
    }
    else {
        PyErr_PrintEx(1);
        #if defined(WIN32) || defined(WINDOWS)
        ERROR_MESSAGE("Error: Failed to import changetext.py module.\nSee changetext.err for details.\n");
        #endif
    }

    initialized = 1; // At least tried to initialize
    return pfuncChangeText!=NULL;
}

#define BUFFER_SIZE 0x100
uint16_t buffer[BUFFER_SIZE];

size_t my_strlen(uint16_t * s) {
    size_t i;
    for(i=0; s[i]; i++);
    return i*sizeof(uint16_t);
}

size_t my_strlen16(uint16_t * s) {
    size_t i;
    for(i=0; s[i]; i++);
    return i;
}

EXPORT std::string ChangeTextString(const std::string src_text) {
  static PyObject * pValue = NULL;
  PyObject * pyString;

  if(!initialized) Init();

  if(pfuncChangeText && pArgs) {
      pyString = PyBytes_FromString(src_text.c_str());
      PyTuple_SetItem(pArgs, 0, pyString);
      Py_XDECREF(pValue);
      pValue = PyObject_CallObject(pfuncChangeText, pArgs);
      if(pValue == Py_None)
          return src_text;

      if(pValue)
          return PyBytes_AS_STRING(pValue);
      else {
          PyErr_PrintEx(1);
          Py_XDECREF(pValue);
          return 0;
      }
  }
  else return src_text;



  return src_text;
}

/* Функция, получающая исходный текст и передающая его на обработку скрипту*/
EXPORT uint16_t * ChangeText(uint16_t * src) {

static PyObject * pValue = NULL;
PyObject * bytesUtf16;

    if(!initialized) Init();

    if(pfuncChangeText && pArgs) {
        bytesUtf16 = PyBytes_FromStringAndSize((char*)src, my_strlen(src));
        PyTuple_SetItem(pArgs, 0, bytesUtf16);
        Py_XDECREF(pValue);
        pValue = PyObject_CallObject(pfuncChangeText, pArgs);
        if(pValue == Py_None)
        {
            return src;
        }

        if(pValue)
            return (uint16_t*)PyBytes_AS_STRING(pValue);
        else {
            PyErr_PrintEx(1);
            Py_XDECREF(pValue);
            return 0;
        }
    }
    else return 0;
}
