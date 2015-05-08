#!/usr/bin/python3.4

#
#find_files.cpp
#music_and_sound_fmodex.cpp
#renderer_curses.cpp

a = """changetext.c
basics.cpp
enabler.cpp
command_line.cpp
enabler_input.cpp
files.cpp
find_files_posix.cpp
graphics.cpp
init.cpp
interface.cpp
keybindings.cpp
KeybindingScreen.cpp
music_and_sound_openal.cpp
random.cpp
renderer_offscreen.cpp
resize++.cpp
textlines.cpp
textures.cpp
ttf_manager.cpp
ViewBase.cpp
win32_compat.cpp"""

header = """
CFLAGS=-c
TAIL=-w --std=c++11 -I/usr/include/
CTAIL=-w --std=c99 -I/usr/include/python3.4m/
BIGINCLUDE=-I/usr/include/gtk-3.0/ -I/usr/include/glib-2.0/ -I/usr/lib/i386-linux-gnu/glib-2.0/include/ -I/usr/include/cairo/ -I/usr/include/pango-1.0/ -I/usr/include/gtk-3.0/gdk/ -I/usr/include/gdk-pixbuf-2.0/ -I/usr/include/atk-1.0/
LINKS=-L. -lSDL -lSDL_ttf -lSDL_image -lGLU -lgobject-2.0 -lgtk-x11-2.0 -lstdc++ -lm -lpython3.4m -lGRP
"""

res = """%(name)s.o: %(name_cpp)s
	gcc -c %(name_cpp)s  $(TAIL) -o %(name)s.o \n"""

cres = """%(name)s.o: %(name_cpp)s
	gcc -c %(name_cpp)s  $(CTAIL) -o %(name)s.o \n"""

big_res = """%(name)s.o: %(name_cpp)s
	gcc -c %(name_cpp)s  $(TAIL) $(BIGINCLUDE) -o %(name)s.o \n"""

target = """all: %(all_obj)s
	gcc -shared -o MYLIB.so %(all_obj)s $(LINKS)
	"""

all_obj = ""

print(header)

for cpp in a.split("\n"):
    name, ext = cpp.split(".")
    all_obj += name + ".o "

print(target % {"all_obj":all_obj})


for cpp in a.split("\n"):
    name, ext = cpp.split(".")
    
    if name in ["enabler", "win32_compat"]:
        print(big_res % {"name":name, "name_cpp":cpp})
        continue
    
    if name in ["changetext"]:
        print(cres % {"name":name, "name_cpp":cpp})
        continue

    print(res % {"name":name, "name_cpp":cpp})





