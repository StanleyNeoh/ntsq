all: run

run: build
	./build/ntsq

test: build
	./build/test_ntsq

build: generate
	cd build; make

generate:
	cmake -S src -B build

.PHONY: generate build
    