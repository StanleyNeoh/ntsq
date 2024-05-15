all: build

run: build
	./build/ntsq

test: build
	./build/test_ntsq

install: build
	cmake --install ./build

build: generate
	cmake --build ./build

generate:
	cmake -S src -B build

.PHONY: run test generate build 
    