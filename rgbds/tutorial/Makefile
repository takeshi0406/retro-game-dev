game: game.z80
	rgbasm -ogame.obj game.z80
	rgblink -mgame.map -ngame.sym -ogame.gb game.obj
	rgbfix -p0 -v game.gb

clean:
	rm -rf *.o *.h *.map *.gbr *.lst *.gb *~