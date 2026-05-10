ALLEGRO_VERSION=5.0.10
MINGW_VERSION=4.7.0
FOLDER=C:

FOLDER_NAME=\allegro-$(ALLEGRO_VERSION)-mingw-$(MINGW_VERSION)
PATH_ALLEGRO=$(FOLDER)$(FOLDER_NAME)
LIB_ALLEGRO=\lib\liballegro-$(ALLEGRO_VERSION)-monolith-mt.a
INCLUDE_ALLEGRO=\include

all: space_invaders_engine.exe


space_invaders_engine.exe: space_invaders_engine.o
	gcc -o space_invaders_engine.exe space_invaders_engine.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

space_invaders_engine.o: space_invaders_engine.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c space_invaders_engine.c	

	
clean:
	rm -f space_invaders_engine.o
	rm -f space_invaders_engine.exe


