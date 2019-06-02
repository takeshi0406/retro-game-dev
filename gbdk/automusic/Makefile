AS = lcc -c
CC = lcc -Wa-l -Wl-m

BIN = automusic.gb
OBJS = main.c piece.c sound.c

all: $(BIN)

%.s: %.ms
	maccer -o $@ $<

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -rf *.o *.map *.gbr *.lst *.gb *~