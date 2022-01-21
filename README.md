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
