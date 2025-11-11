CC = gcc
TARGET = main
SRCS = tcp_server.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
