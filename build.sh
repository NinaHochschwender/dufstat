#!/bin/bash
if [ "$1" = "--debug" ]; then
	flag="-g -c"
else
	flag="-c"
fi
gcc $flag src/du_main.c -o build/du_main.o
gcc $flag src/du.c -o build/du.o
gcc $flag src/du_s.c -o build/du_s.o
gcc $flag src/readtmpfile.c -o build/readtmpfile.o
gcc $flag src/help.c -o build/help.o
gcc build/*.o -o build/app
