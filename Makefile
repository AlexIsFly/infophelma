CFLAGS=-c -g 
LDFLAGS=

testgraphe1: test.o graphefonctions.o liste.o
	gcc  -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) $< 

