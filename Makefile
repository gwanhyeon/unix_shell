CC = gcc
CFLAGS =
OBJS = myShell.c
LIBS =
all : myShell mymv mycp mydate

myShell:$(OBJS)
	$(CC) $(CFLAGS) -o myShell $(OBJS) $(LIBS)
	
mymv:	mymv.c
	$(CC) $(CFLAGS) -o mymv mymv.c

mycp:	mycp.c
	$(CC) $(CFLAGS)	-o mycp mycp.c

mydate:	mydate.c
	$(CC) $(CFLAGS)	-o mydate mydate.c

clean:
	rm -f myShell mymv mycp mydate
