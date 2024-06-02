all: compile link1

compile:
	g++ -c pacman-final.cpp -I"sfml\include" -DSFML_STATIC

link:
	 g++ pacman-final.o -o pacman-final -L"sfml\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lsfml-main

link1:
	g++ pacman-final.o -o pacman-final -L"sfml\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg
