CC = gcc
CFLAGS = -W -Wall
TARGET = main
DTARGET = main_debug
OBJECTS = main.c manager.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o main main_debug
