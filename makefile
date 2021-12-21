# makefile for cpuidtest

all: cpuid
.PHONY: all
%: %.c
	cc -w -o $@ $^
