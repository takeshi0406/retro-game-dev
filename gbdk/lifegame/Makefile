AS = lcc -c
CC = lcc -Wa-l -Wl-m

BIN = lifegame.gb
OBJS = lifegame.c

all: $(BIN)

%.s: %.ms
	maccer -o $@ $<

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -rf *.o *.h *.map *.gbr *.lst *.gb *~