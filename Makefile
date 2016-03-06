
CFLAGS=-c
TAIL=-w --std=c++11 -I/usr/include/
CTAIL=-w --std=c99 -I/usr/include/python3.4m/
BIGINCLUDE=-I/usr/include/gtk-3.0/ -I/usr/include/glib-2.0/ -I/usr/lib/i386-linux-gnu/glib-2.0/include/ -I/usr/include/cairo/ -I/usr/include/pango-1.0/ -I/usr/include/gtk-3.0/gdk/ -I/usr/include/gdk-pixbuf-2.0/ -I/usr/include/atk-1.0/
LINKS=-L. -lSDL -lSDL_ttf -lSDL_image -lGLU -lgobject-2.0 -lgtk-x11-2.0 -lstdc++ -lm -lpython3.4m -lGRP

all: changetext.o basics.o enabler.o command_line.o enabler_input.o files.o find_files_posix.o graphics.o init.o interface.o keybindings.o KeybindingScreen.o music_and_sound_openal.o random.o renderer_offscreen.o resize++.o textlines.o textures.o ttf_manager.o ViewBase.o win32_compat.o 
	gcc -shared -o libgraphics.so changetext.o basics.o enabler.o command_line.o enabler_input.o files.o find_files_posix.o graphics.o init.o interface.o keybindings.o KeybindingScreen.o music_and_sound_openal.o random.o renderer_offscreen.o resize++.o textlines.o textures.o ttf_manager.o ViewBase.o win32_compat.o  $(LINKS)
	
changetext.o: changetext.c
	gcc -c changetext.c  $(CTAIL) -o changetext.o 

basics.o: basics.cpp
	gcc -c basics.cpp  $(TAIL) -o basics.o 

enabler.o: enabler.cpp
	gcc -c enabler.cpp  $(TAIL) $(BIGINCLUDE) -o enabler.o 

command_line.o: command_line.cpp
	gcc -c command_line.cpp  $(TAIL) -o command_line.o 

enabler_input.o: enabler_input.cpp
	gcc -c enabler_input.cpp  $(TAIL) -o enabler_input.o 

files.o: files.cpp
	gcc -c files.cpp  $(TAIL) -o files.o 

find_files_posix.o: find_files_posix.cpp
	gcc -c find_files_posix.cpp  $(TAIL) -o find_files_posix.o 

graphics.o: graphics.cpp
	gcc -c graphics.cpp  $(TAIL) -o graphics.o 

init.o: init.cpp
	gcc -c init.cpp  $(TAIL) -o init.o 

interface.o: interface.cpp
	gcc -c interface.cpp  $(TAIL) -o interface.o 

keybindings.o: keybindings.cpp
	gcc -c keybindings.cpp  $(TAIL) -o keybindings.o 

KeybindingScreen.o: KeybindingScreen.cpp
	gcc -c KeybindingScreen.cpp  $(TAIL) -o KeybindingScreen.o 

music_and_sound_openal.o: music_and_sound_openal.cpp
	gcc -c music_and_sound_openal.cpp  $(TAIL) -o music_and_sound_openal.o 

random.o: random.cpp
	gcc -c random.cpp  $(TAIL) -o random.o 

renderer_offscreen.o: renderer_offscreen.cpp
	gcc -c renderer_offscreen.cpp  $(TAIL) -o renderer_offscreen.o 

resize++.o: resize++.cpp
	gcc -c resize++.cpp  $(TAIL) -o resize++.o 

textlines.o: textlines.cpp
	gcc -c textlines.cpp  $(TAIL) -o textlines.o 

textures.o: textures.cpp
	gcc -c textures.cpp  $(TAIL) -o textures.o 

ttf_manager.o: ttf_manager.cpp
	gcc -c ttf_manager.cpp  $(TAIL) -o ttf_manager.o 

ViewBase.o: ViewBase.cpp
	gcc -c ViewBase.cpp  $(TAIL) -o ViewBase.o 

win32_compat.o: win32_compat.cpp
	gcc -c win32_compat.cpp  $(TAIL) $(BIGINCLUDE) -o win32_compat.o 

