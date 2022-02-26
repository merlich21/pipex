clang -Wall -Wextra -Werror bonus/main_bonus.c bonus/stdin_parser_bonus.c bonus/error_bonus.c bonus/close_fd_bonus.c bonus/childs_bonus.c bonus/list_functions_bonus.c -o pipex
./pipex 1.txt "cat -e" "grep 123" "cat -e" "wc -l" 2.txt
