#include <stdio.h>
#include "help.h"
//a function for showing the help
void help(){
	//test
    printf("%8s%s\n","Usage:","du [OPTION]... [FILE]...");
    printf("%8s%s\n","or:","du [OPTION]... --files0-from=F");
    puts("Summarize disk usage of the set of FILEs, recursively for directories.");
    puts("Mandatory arguments to long options are mandatory for short options too.");
    printf("%-7s%15s%s\n","-0,","--null","end each output line with NUL, not newline");
    printf("%-7s%15s%s\n","-a,","--all","write counts for all files, not just directories");
    printf("%-7s%15s%s\n","","--apparent-size","print apparent sizes, rather than disk usage; although");
    printf("%15s%s\n","","the apparent size is usually smaller, it may be");
    printf("%15s%s\n","","larger due to holes in ('sparse') files, internal");
    printf("%15s%s\n","","fragmentation, indirect blocks, and the like");
    printf("%-7s%15s%s\n","-B,","--block-size=SIZE","scale sizes by SIZE before printing them; e.g.,");
    printf("%15s%s\n","","'-BM' prints sizes in units of 1,048,576 bytes;");
    printf("%15s%s\n","","see SIZE format below");
    printf("%-7s%15s%s\n","-b,","--bytes","equivalent to '--apparent-size --block-size=1'");
    printf("%-7s%15s%s\n","-c,","--total","produce a grand total");
    printf("%-7s%15s%s\n","-D,","--dereference-args","dereference only symlinks that are listed on the");
    printf("%15s%s\n","","command line");
    printf("%-7s%15s%s\n","-d,","--max-depth=N","print the total for a directory (or file, with --all)");
    printf("%15s%s\n","","only if it is N or fewer levels below the command");
    printf("%15s%s\n","","line argument;  --max-depth=0 is the same as");
    printf("%15s%s\n","","--summarize");
    printf("%-7s%15s%s\n","","--files0-from=F","summarize disk usage of the");
    printf("%15s%s\n","","NUL-terminated file names specified in file F;");
    printf("%15s%s\n","","if F is -, then read names from standard input");
    printf("%-7s%15s%s\n","-H","","equivalent to --dereference-args (-D)");
    printf("%-7s%15s%s\n","-h,","--human-readable","print sizes in human readable format (e.g., 1K 234M 2G)");
    printf("%-7s%15s%s\n","","--inodes","list inode usage information instead of block usage");
    printf("%-7s%15s%s\n","-k","","like --block-size=1K");
    printf("%-7s%15s%s\n","-L,","--dereference","dereference all symbolic links");
    printf("%-7s%15s%s\n","-l,","--count-links","count sizes many times if hard linked");
    printf("%-7s%15s%s\n","-m","","like --block-size=1M");
    printf("%-7s%15s%s\n","-P,","--no-dereference","don't follow any symbolic links (this is the default)");
    printf("%-7s%15s%s\n","-S,","--separate-dirs","for directories do not include size of subdirectories");
    printf("%-7s%15s%s\n","","--si","like -h, but use powers of 1000 not 1024");
    printf("%-7s%15s%s\n","-s,","--summarize","display only a total for each argument");
    printf("%-7s%15s%s\n","-t,","--threshold=SIZE","exclude entries smaller than SIZE if positive,");
    printf("%15s%s\n","","or entries greater than SIZE if negative");
    printf("%-7s%15s%s\n","","--time","show time of the last modification of any file in the");
    printf("%15s%s\n","","directory, or any of its subdirectories");
    printf("%-7s%15s%s\n","","--time=WORD","show time as WORD instead of modification time:");
    printf("%15s%s\n","","atime, access, use, ctime or status");
    printf("%-7s%15s%s\n","","--time-style=STYLE","show times using STYLE, which can be:");
    printf("%15s%s\n","","full-iso, long-iso, iso, or +FORMAT;");
    printf("%15s%s\n","","FORMAT is interpreted like in 'date'");
    printf("%-7s%15s%s\n","-X,","--exclude-from=FILE","exclude files that match any pattern in FILE");
    printf("%-7s%15s%s\n","","--exclude=PATTERN","exclude files that match PATTERN");
    printf("%-7s%15s%s\n","-x,","--one-file-system","skip directories on different file systems");
    printf("%-7s%15s%s\n","","--help","display this help and exit");
    printf("%-7s%15s%s\n","","--version","output version information and exit");
    puts("");
    puts("Display values are in units of the first available SIZE from --block-size,");
    puts("and the DU_BLOCK_SIZE, BLOCK_SIZE and BLOCKSIZE environment variables.");
    puts("Otherwise, units default to 1024 bytes (or 512 if POSIXLY_CORRECT is set).");
    puts("");
    puts("The SIZE argument is an integer and optional unit (example: 10K is 10*1024).");
    puts("Units are K,M,G,T,P,E,Z,Y (powers of 1024) or KB,MB,... (powers of 1000).");
}