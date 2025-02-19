CFLAGS=-g -O3

all: srcs

mymain.o: history.h tokenizer.h

srcs: mymain.o tokenizer.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o srcs
