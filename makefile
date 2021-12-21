# makefile for cpustat

all: cpustat
.PHONY: all
%: %.c
	cc -w -o $@ $^
