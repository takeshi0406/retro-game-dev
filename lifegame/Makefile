AS = lcc -c
CC = lcc -Wa-l -Wl-m

BIN = small_sprite.gb
OBJS = small_sprite.o sprite.o

all: $(BIN)

%.s: %.ms
	maccer -o $@ $<

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -rf *.o *.h *.map *.gbr *.lst *.gb *~