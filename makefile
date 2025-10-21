all: Weather.c Football.c
	gcc Weather.c -o Weather
	gcc Football.c -o Football
Weath: Weather.c
	gcc Weather.c -o Weather
footsie: Football.c
	gcc Football.c -o Football