main:
	cc65 -t nes main.c
	ca65 -t nes main.s
	ld65 -t nes main.o nes.lib atmos.lib -o main.nes

clean:
	rm main.o main.nes main.s