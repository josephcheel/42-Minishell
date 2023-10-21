#include "../inc/minishell.h"



int is_redirect(char	*raw_cmd) // return int // control this case 'ls <<<' or 'ls >>>'
{
    int i;
    i = 0;

    while(raw_cmd[i])
    {
        //while((ft_strcmp(&raw_cmd[i], "<") != 0) || ft_strcmp(&raw_cmd[i], ">") != 0)
        //    i++;
        if (raw_cmd[i] == '<' && raw_cmd[i + 1] != '<')
            {
            ft_putstr_fd("1", 2);
            return(1);
            }
        else if (raw_cmd[i] == '>' && raw_cmd[i + 1] != '>')
            {
            ft_putstr_fd("2", 2);
            return(2);
            }
        else if (raw_cmd[i] == '>' && raw_cmd[i + 1] == '>')
            {
            ft_putstr_fd("3", 2);
            return(3);
            }
        else if (raw_cmd[i] == '<'&& raw_cmd[i + 1] == '<')
            {
            ft_putstr_fd("4", 2);
            return(4);
            }
        
        i++;
    }
    return(0);
}




//-------------------------------------------------------------------------------
/*
void    in_file_top(TEXT, FILE)
{
    int fd;

    fd = open("(output.txt)FILE", O_WRONLY | O_CREAT | O_TRUNC, 0666); // You can replace "output.txt" with the desired file name
    if (fd == -1) 
        {
        perror("open");
        exit(1);
        }
    if (dup2(fd, STDOUT_FILENO) == -1) 
        {
        perror("dup2");
        exit(1);
        }
    close(fd);  
    //execve

}
//dup2 function duplicate the filedescriptor

void from_file_top(TEXT, FILE)
{
    int fd;

    fd = open(FILE, O_RDONLY);
    if (fd == -1) 
    {
        perror("open");
        exit(1);
    }
    if (dup2(fd, STDIN_FILENO) == -1) 
    {
        perror("dup2");
        exit(1);
    }
    close(fd);
    if (execve(fullpath, args, NULL) == -1) 
    {
        perror("execve");
        exit(1);
    }

}

void in_file_bottom(TEXT, FILE)
{
    int fd;

    fd = open(FILE, O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd == -1) 
    {
        perror("open");
        exit(1);
    }
    if (dup2(fd, STDOUT_FILENO) == -1) 
    {
        perror("dup2");
        exit(1);
    }
    close(fd);
    if (execve(fullpath, args, NULL) == -1) 
    {
        perror("execve");
        exit(1);
    }

}

void from_file_bottom
{
    char *input = "ls -l > output.txt"; // Replace with your desired command
    char *command, *filename;
    
    // Split the input into command and filename
    command = strtok(input, ">");
    filename = strtok(NULL, ">");
    
    // Trim leading and trailing spaces from filename
    while (filename && *filename && (*filename == ' ' || *filename == '\t')) {
        ++filename;
    }
    size_t len = strlen(filename);
    while (len > 0 && (filename[len - 1] == ' ' || filename[len - 1] == '\t')) {
        --len;
    }
    filename[len] = '\0';

    // Open the file for writing
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    
    // Redirect stdout to the file descriptor
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(1);
    }
    
    // Close the file descriptor
    close(fd);
    
    // Split the command into arguments
    char *args[] = {command, NULL};
    
    // Provide the full path to the executable
    char *fullpath = "/bin/ls"; // Replace with the correct path to the executable
    
    // Execute the command using execve
    if (execve(fullpath, args, NULL) == -1) {
        perror("execve");
        exit(1);
    }
    
    // This code will not be reached if execve is successful
    exit(0);
}*/