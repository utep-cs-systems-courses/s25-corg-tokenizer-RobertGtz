CFLAGS=-g -O3

all: srcs

mymain.o: history.h tokenizer.h

srcs: mymain.o tokenizer.o history.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o srcs
