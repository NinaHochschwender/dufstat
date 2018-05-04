#include <stdio.h>
#include "help.h"
#define ARGS "%7s%-20s%s\n"
#define HEAD "%8s%s\n"
#define TEXT "%27s%s\n"

//a function for showing the help
void help(){
	//test
    printf(HEAD,"Usage:","du [OPTION]... [FILE]...");
    printf(HEAD,"or:","du [OPTION]... --files0-from=F");
    puts("Summarize disk usage of the set of FILEs, recursively for directories.");
    puts("Mandatory arguments to long options are mandatory for short options too.");
    printf(ARGS,"-0,","--null","end each output line with NUL, not newline");
    printf(ARGS,"-a,","--all","write counts for all files, not just directories");
    printf(ARGS,"","--apparent-size","print apparent sizes, rather than disk usage; although");
    printf(TEXT,"","the apparent size is usually smaller, it may be");
    printf(TEXT,"","larger due to holes in ('sparse') files, internal");
    printf(TEXT,"","fragmentation, indirect blocks, and the like");
    printf(ARGS,"-B,","--block-size=SIZE","scale sizes by SIZE before printing them; e.g.,");
    printf(TEXT,"","'-BM' prints sizes in units of 1,048,576 bytes;");
    printf(TEXT,"","see SIZE format below");
    printf(ARGS,"-b,","--bytes","equivalent to '--apparent-size --block-size=1'");
    printf(ARGS,"-c,","--total","produce a grand total");
    printf(ARGS,"-D,","--dereference-args","dereference only symlinks that are listed on the");
    printf(TEXT,"","command line");
    printf(ARGS,"-d,","--max-depth=N","print the total for a directory (or file, with --all)");
    printf(TEXT,"","only if it is N or fewer levels below the command");
    printf(TEXT,"","line argument;  --max-depth=0 is the same as");
    printf(TEXT,"","--summarize");
    printf(ARGS,"","--files0-from=F","summarize disk usage of the");
    printf(TEXT,"","NUL-terminated file names specified in file F;");
    printf(TEXT,"","if F is -, then read names from standard input");
    printf(ARGS,"-H ","","equivalent to --dereference-args (-D)");
    printf(ARGS,"-h,","--human-readable","print sizes in human readable format (e.g., 1K 234M 2G)");
    printf(ARGS,"","--inodes","list inode usage information instead of block usage");
    printf(ARGS,"-k ","","like --block-size=1K");
    printf(ARGS,"-L,","--dereference","dereference all symbolic links");
    printf(ARGS,"-l,","--count-links","count sizes many times if hard linked");
    printf(ARGS,"-m ","","like --block-size=1M");
    printf(ARGS,"-P,","--no-dereference","don't follow any symbolic links (this is the default)");
    printf(ARGS,"-S,","--separate-dirs","for directories do not include size of subdirectories");
    printf(ARGS,"","--si","like -h, but use powers of 1000 not 1024");
    printf(ARGS,"-s,","--summarize","display only a total for each argument");
    printf(ARGS,"-t,","--threshold=SIZE","exclude entries smaller than SIZE if positive,");
    printf(TEXT,"","or entries greater than SIZE if negative");
    printf(ARGS,"","--time","show time of the last modification of any file in the");
    printf(TEXT,"","directory, or any of its subdirectories");
    printf(ARGS,"","--time=WORD","show time as WORD instead of modification time:");
    printf(TEXT,"","atime, access, use, ctime or status");
    printf(ARGS,"","--time-style=STYLE","show times using STYLE, which can be:");
    printf(TEXT,"","full-iso, long-iso, iso, or +FORMAT;");
    printf(TEXT,"","FORMAT is interpreted like in 'date'");
    printf(ARGS,"-X,","--exclude-from=FILE","exclude files that match any pattern in FILE");
    printf(ARGS,"","--exclude=PATTERN","exclude files that match PATTERN");
    printf(ARGS,"-x,","--one-file-system","skip directories on different file systems");
    printf(ARGS,"","--help","display this help and exit");
    printf(ARGS,"","--version","output version information and exit");
    puts("");
    puts("Display values are in units of the first available SIZE from --block-size,");
    puts("and the DU_BLOCK_SIZE, BLOCK_SIZE and BLOCKSIZE environment variables.");
    puts("Otherwise, units default to 1024 bytes (or 512 if POSIXLY_CORRECT is set).");
    puts("");
    puts("The SIZE argument is an integer and optional unit (example: 10K is 10*1024).");
    puts("Units are K,M,G,T,P,E,Z,Y (powers of 1024) or KB,MB,... (powers of 1000).");
}
