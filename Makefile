PROJ = dinionctrl
CFLAGS = -g -std=c99 -Wall 
LIB = -lrcpplus-1.0.0 -ltlog-1.0.0 -lpthread
SRCS = main.c 
INCL = 
OBJS = $(SRCS:.c=.o)

.PHONY: clean

all: $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(PROJ)

.c.o: 
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

clean:
	rm -rf $(OBJS) $(PROJ)

