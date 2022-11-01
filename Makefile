CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
ED_OBJECTS = main.o EDistance.o

all: EDistance

EDistance: $(ED_OBJECTS)
	$(CC) $(CFLAGS) -o EDistance $(ED_OBJECTS) $(LIBS)

%.o: %.c
	$(CC) -g $(CFLAGS) -o $@ $<

clean:
	rm EDistance *.o