build:
	gcc src/main.c -o build/defensegame

run:
	gcc src/main.c -o build/defensegame
	./build/defensegame

clean:
	rm -rf build/*
