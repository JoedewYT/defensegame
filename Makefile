build:
	gcc src/main.c -o build/defensegame.exe

run:
	gcc src/main.c -o build/defensegame.exe
	./build/defensegame.exe

clean:
	rm build/*