#!/bin/bash

RESET="\033[0m"
GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[33m"
CYAN="\033[36m"
RED="\033[31m"

execute_command() {
	printf $CYAN"command : $1\n"$RESET
	./minishell "$1"
	EXIT_STATUS=$?
	if [[ "$1" == *exit* ]]
	then
		printf $RED"exit status : $EXIT_STATUS\n"
	fi
	echo
}

printf $YELLOW"Start minishell tester\n"$RESET
echo

printf $YELLOW"############################# echo #############################\n"$RESET
echo

execute_command "echo"
execute_command "echo 123"
execute_command "echo -n 456"
execute_command "echo -nnnnnnn 456"
execute_command "echo -nnnnnnnsdf 456"
execute_command "echo -nnnnnnnsdf -nn 456"

printf $YELLOW"############################ cd && pwd  ############################\n"$RESET
echo

execute_command "pwd"
execute_command "pwd && cd && pwd"
execute_command "pwd && cd .. && pwd"
execute_command "pwd && cd . && pwd"
execute_command "pwd && ls && cd srcs && pwd"
execute_command "pwd && cd /Users/kangmin && pwd"
execute_command "cd 123 || pwd"
execute_command "pwd 123"
execute_command "pwd isdnf"

printf $YELLOW"######################### export && unset && env #########################\n"$RESET
echo

execute_command "export"
execute_command "unset"
execute_command "env"
execute_command "export test=test && env"
execute_command "export test=test && export test=test123 && env"
execute_command "export test=test && unset test && env"
execute_command "export 123"
execute_command "export nksdf && env"
execute_command "ls"
execute_command "unset PATH && ls"

printf $YELLOW"######################### exit && exit_status #########################\n"$RESET
echo

execute_command "exit"
execute_command "exit sldfk"
execute_command "exit 123"
execute_command "exit 12 123"
execute_command "exit sdjklf 123"
execute_command "exit 123"

printf $YELLOW"######################### double quotes #########################\n"$RESET
echo

execute_command "echo 'text1.txt contents' && echo cat text1.txt | cat > result1.txt"
execute_command "echo \"cat text1.txt | cat > result1.txt\""
execute_command "echo \"\$PATH\""

printf $YELLOW"######################### single quote #########################\n"$RESET
echo

execute_command "echo 'text1.txt contents' > text1.txt && cat text1.txt"
execute_command "echo 'cat text1.txt | cat > result1.txt'"
execute_command "echo '\$PATH'"
execute_command "echo \"'\$PATH'\""
execute_command "echo '\"\$PATH\"'"

printf $YELLOW"######################### redirections #########################\n"$RESET
echo

execute_command "echo 'text2.txt contents' > text2.txt && cat text2.txt"
execute_command "cat < text2.txt"
execute_command "cat text2.txt > result2.txt && cat result2.txt"
execute_command "cat text1.txt"
execute_command "cat text2.txt > result1.txt > result2.txt && cat result1.txt && cat result2.txt"
execute_command "cat text1.txt > result1.txt > result2.txt && cat result1.txt && cat result2.txt"
#execute_command "cat < text1.txt < text2.txt"
#execute_command "cat < text2.txt < text1.txt"

rm text*.txt result*.txt
