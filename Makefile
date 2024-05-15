all: build

run: build
	./build/ntsq

test: build
	./build/test_ntsq

build: generate
	cmake --build ./build

generate:
	cmake -S src -B build

.PHONY: generate build
    