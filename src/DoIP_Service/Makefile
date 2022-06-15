TARGET = libdoip_server.so
CC = gcc 
AR = ar rcs
CFLASS = -Wall 
LIBS = -lpthread

# header file
INCS = -I./adapter/include -I./common/include/ -I./doip/include -I./interface/include\
	   -I./soad/include -I./uds/include

#source file
SRCS := $(wildcard ./adapter/source/*.c ./common/source/*.c ./doip/source/*.c \
		./interface/*.c ./soad/source/*.c ./uds/source)
COBJS := $(SRCS:.c=.o)

all:$(TARGET)

$(TARGET):$(COBJS)
	$(CC) $(COBJS) $(LIBS) -shared -fPIC -o $(TARGET)
	cp $(TARGET) /usr/lib

$(COBJS):%.o:%.c
	$(CC) -c $< -o $@ $(INCS) $(CFLASS)

clean:
	rm $(TARGET) $(COBJS)
