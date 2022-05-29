all: clean build

build:
	g++ src/app.cpp -o bin/app -Isrc

clean:
	rm bin/app

run:
	./bin/app $(ARGS)

