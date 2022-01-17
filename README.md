# 42seoul-minishell
## Summary
The objective of this project is for you to create a simple shell.\
Yes, your little bash or zsh.\
You will learn a lot about processes and file descriptors.

## Introduction
The existence of shells is linked to the very existence of IT.\
At the time, all coders agreed that <b>communicating with a computer using aligned 1/0 switches was seriously irritating.</b>\
It was only logical that they came up with the idea to <b>communicate with a computer using interactive lines of commands in a language somewhat close to english.</b>\
\
With <b>Minishell</b>, you'll be able to travel through time and come back to problems people faced when <b>Windows</b> didn't exist.

## Common Instructions
- Norm
- No error (segmentation falut, bus error, double free, etc)
- No leaks
- Compile flags (-Wall -Wextra -Werror)
- Makefile must not relink
- Makefile rules ($(NAME), all, clean, fclean, re)
- To turn in bonuses, must include a rule bonus
- Bonuses must be in a different file <b>_bonus.{c/h}</b>.

## Mandatory part
![image](https://user-images.githubusercontent.com/74703501/149716118-62c5ad10-44cd-401e-9b85-e77135fbb97a.png)\
\
Your shell should:
- Not interpret unclosed quotes or unspecified special characters like \\ or ;.
- Not use more than one global variable, think about it and be ready to explain why you do it.
- Show a prompt when waiting for a new command.
- Have a working History.
- Search and launch the right executable (based on the <b>PATH</b> variable or by using relative or absolute path)
- It must implement the builtins:
  - <b>echo</b> with option -n
  - <b>cd</b> with only a relative or absolute path
  - <b>pwd</b> with no options
  - <b>export</b> with no options
  - <b>unset</b> with no options
  - <b>env</b> with no options or arguments
  - <b>exit</b> with no options
- \' inhibit all interpretation of a sequence of characters.
- \" inhibit all interpretation of a sequence of characters except for \$.
- Redirections:
  - \< should redirect input.
  - \> should redirect output.
  - "<<" read input from the current source until a line containing only the 
    delimiter is seen. it doesn't need to update history!
  - ">>" should redirect output with append mode.
- Pipes \| The output of each command in the pipeline is connected via a pipe 
  to the input of the next command.
- Environment variables (\$ followed by characters) should expand to their 
  values.
- "$?" should expands to the exit status of the most recently executed 
  foreground pipeline.
- "ctrl-C" "ctrl-D" ctrl-\\" should work like in bash.
- When interative:
  - "ctrl-C" print a new prompt on newline.
  - "ctrl-D" exit the shell.
  - "ctrl-\\" do nothing.
Anything not asked is not required.\
For every point, if you have any doubt take [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) as a reference.

## Bonus part
- If the Mandatory part is not perfect don't even think about bonuses
- "&&", "||" with parenthesis for priorities.
- the wildcard \* should work for the current working directory.
