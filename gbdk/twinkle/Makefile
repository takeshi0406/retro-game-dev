AS = lcc -c
CC = lcc -Wa-l -Wl-m

BIN = twinkle.gb
OBJS = twinkle.o

all: $(BIN)

%.s: %.ms
	maccer -o $@ $<

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -rf $(BIN) $(OBJS) twinkle.lst twinkle.map *~
