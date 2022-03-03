# pipex

MANDATORY PART: (make)

The program will be executed as follows:

./pipex file1 cmd1 cmd2 file2

It takes 4 arguments:

• file1 and file2 are file names.
• cmd1 and cmd2 are shell commands with their parameters.

It behaves exactly the same as the shell command below:

$> < file1 cmd1 | cmd2 > file2

Examples:

1) $> ./pipex infile "ls -l" "wc -l" outfile

Will behave like: < infile ls -l | wc -l > outfile

2) $> ./pipex infile "grep a1" "wc -w" outfile

Will behave like: < infile grep a1 | wc -w > outfile
_________________________________________________________
BONUS PART: (make bonus)

1. The program handles multiple pipes.

This:
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

Will behave like:
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

*********************************************************
2. The program supports « and » when the first parameter is "here_doc".

This:
$> ./pipex here_doc LIMITER cmd cmd1 file

Will behave like:
cmd << LIMITER | cmd1 >> file
