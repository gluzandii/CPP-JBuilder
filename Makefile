all: clean build

build:
	clang++ src/app.cpp -o bin/app -Isrc

clean:
	rm bin/app

run:
	./bin/app $(ARGS)