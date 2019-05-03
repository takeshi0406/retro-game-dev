AS = lcc -c
CC = lcc -Wa-l -Wl-m

BIN = object_oriented.gb
OBJS = object_oriented.c Player.c

all: $(BIN)

%.s: %.ms
	maccer -o $@ $<

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -rf *.o *.map *.gbr *.lst *.gb *~