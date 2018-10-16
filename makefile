make: org.c org.h
	gcc org.c
	gcc org.h

debug: org.c org.h
	gcc -g org.c
	gcc -g org.h

clean: a.out org.h.gch
	rm a.out
	rm org.h.gch

run: a.out
	./a.out
