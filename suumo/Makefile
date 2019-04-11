AS = lcc -c
CC = lcc -Wa-l -Wl-m

BIN = suumo.gb
OBJS = suumo.c ufo.c

all: $(BIN)

%.s: %.ms
	maccer -o $@ $<

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -rf *.o *.map *.gbr *.lst *.gb *~