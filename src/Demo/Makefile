TARGET = doip_server
CC = gcc 
AR = ar rcs
CFLASS = -Wall
LIBS = -ldoip_server

# header file
INCS = -I./include/

#source file
SRCS := $(wildcard ./*.c)
COBJS := $(SRCS:.c=.o)

all:$(TARGET)

$(TARGET):$(COBJS)
	$(CC) $(COBJS) $(LIBS) -o $(TARGET)

$(COBJS):%.o:%.c
	$(CC) -c $< -o $@ $(INCS) $(CFLASS)

clean:
	rm $(TARGET) $(COBJS)
	rm demo.log
