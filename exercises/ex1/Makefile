#compiler
CC=g++

#directories
INCDIR=include
OBJDIR=obj

#flags
CFLAGS=-c -I$(INCDIR)
OBJECTS= main.o $(OBJDIR)/coords.o $(OBJDIR)/function.o

ex1.x: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -rf *.o *.x
