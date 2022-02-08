#!/bin/bash

RESET="\033[0m"
GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[33m"
CYAN="\033[36m"
RED="\033[31m"

execute_command() {
	printf $GREEN"command : $1\n"$RESET
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

execute_command "cat << next"
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

execute_command "cat << next"
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

execute_command "cat << next"
printf $YELLOW"####################### exit && exit_status && \$? #######################\n"$RESET
echo

execute_command "exit"
execute_command "exit sldfk"
execute_command "exit 123"
execute_command "exit 12 123"
execute_command "exit sdjklf 123"
execute_command "exit 123"
execute_command "pwd && echo \$?"

execute_command "cat << next"
printf $YELLOW"######################### double quotes #########################\n"$RESET
echo

execute_command "echo 'text1.txt contents' && echo cat text1.txt | cat > result1.txt"
execute_command "echo \"cat text1.txt | cat > result1.txt\""
execute_command "echo \"\$PATH\""

execute_command "cat << next"
printf $YELLOW"######################### single quote #########################\n"$RESET
echo

execute_command "echo 'text1.txt contents' > text1.txt && cat text1.txt"
execute_command "echo 'cat text1.txt | cat > result1.txt'"
execute_command "echo '\$PATH'"
execute_command "echo \"'\$PATH'\""
execute_command "echo '\"\$PATH\"'"

execute_command "cat << next"
printf $YELLOW"######################### single redirections #########################\n"$RESET
echo

execute_command "echo 'text2.txt contents' > text2.txt && cat text2.txt"
execute_command "cat < text2.txt"
execute_command "cat text2.txt > result2.txt && cat result2.txt"
execute_command "cat text1.txt"
execute_command "cat text2.txt > result1.txt > result2.txt"
execute_command "cat result1.txt"
execute_command "cat result2.txt"
execute_command "cat text1.txt > result2.txt > result1.txt"
execute_command "cat result1.txt"
execute_command "cat result2.txt"
execute_command "cat < text1.txt < text2.txt"
execute_command "cat < text2.txt < text1.txt"
execute_command "cat text1.txt > result1.txt > result2.txt && cat result2.txt"
execute_command "cat text1.txt > result2.txt > result1.txt && cat result1.txt"
execute_command "cat text1.txt > result2.txt > result1.txt && cat result1.txt"

execute_command "cat << next"
printf $YELLOW"######################### double redirections #########################\n"$RESET
echo

execute_command "cat << end1"
execute_command "cat << end1 << end2"
execute_command "cat << end1 > result1.txt"
execute_command "cat result1.txt"
execute_command "cat << end1 >> result1.txt"
execute_command "cat result1.txt"
execute_command "cat << end1 > result1.txt >> result2.txt"
execute_command "cat result1.txt"
execute_command "cat result2.txt"

execute_command "cat << next"
printf $YELLOW"######################### pipes #########################\n"$RESET
echo

execute_command "echo pipe test | cat"
execute_command "ls | wc"
execute_command "ls | wc | exit | echo 123"
execute_command "cat < tester.sh | grep printf > result4.txt"
execute_command "cat result4.txt"
execute_command "cat < text1.txt | wc"

execute_command "cat << next"
printf $YELLOW"######################### environment variables  #########################\n"$RESET
echo

execute_command "env"
execute_command "echo \$PATH"
execute_command "echo \$LOGNAME"
execute_command "echo \$PWD"
execute_command "echo \$OLDPWD"
execute_command "echo \$PATH && unset PATH && echo \$PATH"
execute_command "echo \$LOGNAME && unset LOGNAME && echo \$LOGNAME && export LOGNAME=kangmin && echo \$LOGNAME"

execute_command "cat << next"
printf $YELLOW"######################### ||, &&, parenthesis #########################\n"$RESET
echo

execute_command "echo 123 || echo 456"
execute_command "echo 123 && echo 456"
execute_command "echo 123 || echo 456 || echo 789"
execute_command "echo 123 && echo 456 && echo 789"
execute_command "(echo 123 || echo 456) && echo 789"
execute_command "(echo 123 && echo 456) && echo 789"
execute_command "(cd 123 || echo 123) || echo 456"
execute_command "(cd 123 && echo 123) || echo 456"

printf $YELLOW"# Next Step : Explain why we use a global variable\n"$RESET
printf $YELLOW"# Next Step : Show history\n"$RESET
printf $YELLOW"# Next Step : return value of a process\n"$RESET
printf $YELLOW"# Next Step : Show signal controls (ctrl-C, ctrl-D ctrl-\\)\n"$RESET
echo

rm text*.txt result*.txt
