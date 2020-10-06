cc = gcc
CFLAGS = -g -c
.SUFFIX:.c .o

TARGET = fmt
OBJECTS = main.o Output.o String_Manipulation.o

#. SUFFIX
.c .o:
	$(CC) $(CFLAGS) -o $@ $<
$(TARGET) : $(OBJECTS)
		$(cc) -g -o $@ $(OBJECTS)
$(OBJECTS) : Header.h

.phony : clean
clean:
	rm *.o fmt
