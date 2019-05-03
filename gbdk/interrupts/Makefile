AS = lcc -c
CC = lcc -Wa-l -Wl-m

BIN = interrupts.gb
OBJS = interrupts.c

all: $(BIN)

%.s: %.ms
	maccer -o $@ $<

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -rf *.o *.h *.map *.gbr *.lst *.gb *~