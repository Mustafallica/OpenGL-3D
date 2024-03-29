CPP = g++
LD = g++
CPPFLAGS = -O3 -fPIC -Wno-deprecated-declarations
LDFLAGS = -O3
TARGET = hw2
OBJS = hw2.o
OS = $(shell uname)

ifeq ($(OS),Darwin)
	LIB =  -framework GLUT -framework OpenGL -framework Cocoa
else
	LIB =  -lGL -lGLU -lglut
endif

default: $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) $(LIB) -o $(TARGET)

main.o: main.cpp
	$(CPP) -c $(CPPFLAGS) hw2.cpp

clean:
	rm -f *.o $(TARGET)
