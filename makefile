# makefile for cpuidtest

all: cpuid
.PHONY: all
%: %.c
	gcc -o $@ $^
