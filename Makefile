all: run

run: build
	cd build; ./ntsq;

build: generate
	cd build; make

generate:
	cmake -S src -B build

.PHONY: generate build
    