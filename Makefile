all: clean build

build:
	g++ src/app.cpp -o bin/sjb -Isrc

clean:
	rm bin/sjb

run:
	./bin/sjb $(ARGS)

