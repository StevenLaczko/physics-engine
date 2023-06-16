CC = g++
CFLAGS = -std=c++11 -Wall -I/usr/local/include/SDL2/

LIBS = -lSDL2

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
EXECUTABLE = simulation

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXECUTABLE) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)
