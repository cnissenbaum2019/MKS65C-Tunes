make: song.c song.h
	gcc song.c
	gcc song.h

debug: song.c song.h
	gcc -g song.c
	gcc -g song.h

clean: a.out song.h.gch
	rm a.out
	rm song.h.gch

run: a.out
	./a.out
