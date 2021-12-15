# makefile for mac cpuid

all: cpuidmac
.PHONY: all
%: %.c
	gcc -o $@ $^
