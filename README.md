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

## Functions
```c
// The function readline() prints a prompt prompt and then reads and returns a single line of text from the user.
// If prompt is NULL or the empty string, no prompt is displayed.
// If readline encounters an EOF while reading the line, and the line is empty at that point, the (char *)NULL is returned.
// Otherwise, the line is ended just as if a newline had been typed.
char *readline(const char *prompt);

// Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline.
int   rl_on_new_line(void);

// Replace the contents of rl_line_buffer with text.
// The point and mark are preserved, if possible.
// If clear_undo is non-zero, the undo list associated with the current line is cleared.
void  rl_replace_line(const char *text, int clear_undo);

// Change what's displayed on the screen to reflect the current contents of rl_line_buffer.
void  rl_redisplay(void);

// Place string at the end of the history list.
// The associated data field (if any) is set to NULL.
// If the maximum number of history entries has been set using stifle_history(),
// and the new number of history entries would exceed that maximum,
// the oldes history entry is removed.
void  add_history(const char *string);

int   printf(const char * restrict format, ...);
void  *malloc(size_t size);
void  free(void *ptr);
ssize_t write(int fildes, const void *buf, size_t nbyte);
int   open(const char *path, int oflag, ...);
ssize_t read(int fildes, void *buf, size_t nbyte);
int   close(int fildes);

// create a new process
pid_t fork(void);

// wait for process termination
pid_t wait(int *stat_loc);
pid_t waitpid(pid_t pid, int *stat_loc, int options);
pid_t wait3(int *stat_loc, int options, struct rusage *rusage);
pid_t wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage);

// simplified software signal facilities
// typedef void (*sig_t)(int);
// sig_t signal(int sig, sig_t func);
void  (*signal)(int sig, void (*func)(int))(int);

// send signal to a process
int   kill(pid_t pid, int sig);

// perform normal program termination
void  exit(int status);

// get working directory pathname
char  *getcwd(char *buf, size_t size);

// change current working directory
int   chdir(const char *path);

// get file status
int   stat(const char *restrict path, struct stat *restrict buf);
int   lstat(const char *restrict path, struct stat *restrict buf);
int   fstat(int fd, const char *path, struct stat *buf, int flag);

// remove directory entry
int   unlink(const char *path);

// execute a file
int   execve(const char *path, char *const argv[], char *const envp[]);

// duplicate an existing file descriptor
int   dup(int fildes);
int   dup2(int fildes, int fildes2);

// create descriptor pair for interprocess communication
int    pipe(int fildes[2]);

// directory operations
DIR   *opendir(const char *filename);
struct dirent *readdir(DIR *dirp);
int   closedir(DIR *dirp);

// system error messages
char  *strerror(int errnum);

// Nearly all of the system calls provide an error number in the external variable
extern int  errno

// get name of associated terminal (tty) from file descriptor
int   isatty(int fd);
char  *ttyname(int fd);

// find the slot of the current user's terminal in some file
int   ttyslot(void);

// control device
int   ioctl(int fildes, unsigned long request, ...);

// environment variable functions
char  *getenv(const char *name);

// manipulating the termios structure
int   tcsetattr(int fildes, int optional_actions, const struct termios *termios_p);
int   tcgetattr(int fildes, struct termios *termios_p);

// direct curses interface to the terminfo capability database
int   tgetent(char *bp, const char *name);
int   tgetflag(char *id);
int   tgetnum(char *id);
char  *tgetstr(char *id, char **area);
char  *tgoto(const char *cap, int col, int row);
int   tputs(const char *str, int affcnt, int (*putc)(int));
```
## Command
- echo (with option -n)
  - write arguments to the standard output
  - Description
    - The echo utility writes any specified operands, separated by single blank(' ') characters and followed by a newline ('\n') character, to the standard output.
  - option
    - -n : Do not print the trailing newline character

- cd (with only a relative or absolute path)
  - change the working directory
  - The cd utility shall change the working directory of the current shell execution environment by executing the following steps in sequence

- pwd (with no options)
  - return working directory name
  - Description
    - The pwd utility writes the absolute pathname of the current working directory to the standard output.

- export (with no options)
  - set the export attribute for variables
  - Description
    - The shell shall give the export attribute to the variables corresponding to the specified names, which shall cause them to be in the environment of subsequently executed commands

- unset (with no options)
  - unset values and attributes of variables and functions
  - Description
    - Each variable or function specified by name shall be unset

- env (with no options or arguments)
  - set environment and execute command, or print environment

- exit (with no options)
  - cause normal process termination
  - Description
    - The exit() function causes normal process termination and the least significant byte of status is returned to the parent

## What I Learned
- bash
- special characters
- history
- environment variables
- builtin commands
- single quotes, double quotes
- redirections
- pipe
- exit status
- signal
- terminal control
- &&, || with parenthesis

### General Reviews
minishell 과제는 bash의 몇 가지 기능을 구현하는 과제이다.
이 과제에서 배운 것은 지금까지 학습했던 내용 보다 많은 것 같다.
특히 프로세스와 파일 디스크립터에 대해 조금 더 알 수 있었다.
이 과제에서는 이전까지 학습했던 과제의 내용들을 필요로 했다.
파일 디스크립터, 시그널, 파이프를 기반으로 과제를 수행해야만 했는데, 파이프 과제를 진행하지 않아서 따로 학습해야만 했다.
위 3가지의 개념을 기반으로 입력된 문자열의 어휘 분석과 구문 분석, 리다이렉션, 프로세스 등 여러 가지를 구현했다.
bash와 완전히 동일하게 작동하지는 않지만, 큰 틀에서 따라 하려고 노력했다.
이 과제에서 학습한 내용들을 전부 습득하진 못 했지만, 내가 맡은 부분이 아닌 어휘 분석과 구문 분석 부분은 따로 추가적인 학습을 진행해야겠다.
과제가 끝난 뒤 Cjeon 님께서 시간을 내서 나의 과제를 확인해 주셨는데, 내가 생각하지 못한 부분을 말해주셨다.
그 부분을 수정하면서 내가 몰랐던 부분을 알 수 있었고 이런 기회를 준 Cjeon 님에게 감사하다.
다음 과제도 이번 과제와 같이 최선을 다해 효율적으로 학습할 수 있도록 해야겠다.
