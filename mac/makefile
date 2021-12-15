# makefile for mac cpuid

all: cpuidmac
.PHONY: all
%: %.asm
	nasm -f macho64 $^
	ld -o $@ $@.o
