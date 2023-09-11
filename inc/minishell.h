#ifndef MINISHELL_H
#define MINISHELL_H
#include <sys/types.h> //pthread
#include <sys/stat.h> //defines the structure of the data returned by the functions fstat(), lstat(), and stat(). 
#include <sys/wait.h> // constants for use with waitpid()
#include <unistd.h>
#include <stdlib.h>
#include <signal.h> //minitalk
#include <dirent.h> //format of directory entries (init of a directory)
#include "libft.h"
#include <stdio.h>

/* The structure stat (sys/stat.h) contains at least the following members:


	dev_t     st_dev     ID of device containing file
	ino_t     st_ino     file serial number
	mode_t    st_mode    mode of file (see below)
	nlink_t   st_nlink   number of links to the file
	uid_t     st_uid     user ID of file
	gid_t     st_gid     group ID of file
	dev_t     st_rdev    device ID (if file is character or block special)
	off_t     st_size    file size in bytes (if file is a regular file)
	time_t    st_atime   time of last access
	time_t    st_mtime   time of last data modification
	time_t    st_ctime   time of last status change
	blksize_t st_blksize a filesystem-specific preferred I/O block size for
                     this object.  In some filesystem types, this may
                     vary from file to file
	blkcnt_t  st_blocks  number of blocks allocated for this object
*/

#define IS_QUOTE(x) (x == '"' || x == '\'')

char **g_envv;

/*
** src/cd_builtin.c
*/
void change_dir(char *path, int print_path);
int cd_builtin(char **command);

/*
** src/display_prompt_msg.c
*/
void exit_shell(void);
char *parse_home_path(char *path, int reverse_parse);
void display_prompt_msg(void);

/*
** src/echo_builtin.c
*/
int echo_builtin(char **command);

/*
** src/exec_command.c
*/
int exec_command(char **command);

/*
** src/setenv_builtin.c
*/
int find_env_var(char *var);
char *get_env_var(char *var);
char **realloc_envv(int new_size);
void set_env_var(char *key, char *value);
int setenv_builtin(char **command);
int setenv_builtin(char **args);

/*
** src/signal_handler.c
*/
void signal_handler(int signo);
void proc_signal_handler(int signo);

/*
** src/unsetenv_builtin.c
*/
void print_env(void);
void init_envv(int ac, char **av, char **envv);
int unsetenv_builtin(char **command);
#endif

