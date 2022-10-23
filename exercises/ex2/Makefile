#compiler
CC=g++

#directories
INCDIR=include
OBJDIR=obj

#flags
CFLAGS=-c -I$(INCDIR)
OBJECTS= main.o $(OBJDIR)/coeffs.o $(OBJDIR)/equation.o $(OBJDIR)/complex.o

ex2.x: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -rf *.o *.x
