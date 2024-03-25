#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int READ_END = 0;
const int WRITE_END = 1;

int     g_ac;
char    **g_av;
int     g_av_idx = 1;
int     g_process_cnt = 0;
int     g_fd[2];
int     g_prev_fd;

// ["a.out", "/bin/ls", "|", "/bin/cat", "|", "/bin/cat", "|", "/bin/cat"]

void cd()
{
    chdir(g_av[++g_av_idx]);
    system("pwd");
    printf("%s\n", g_av[g_av_idx]);
}

int get_pipe_cnt()
{
    int cnt = 0;

    for (int i = 1; i < g_ac; i++)
    {
        if (strncmp(g_av[i], "|", 2) == 0)
        {
            ++cnt;
        }
        if (strncmp(g_av[i], ";", 2) == 0)
        {
            return (cnt);
        }
    }
    return (cnt);
}

int get_command_cnt()
{
    int cnt = 1;

    for (int i = 1; i < g_ac; i++)
    {
        if (strncmp(g_av[i], ";", 2) == 0)
        {
            ++cnt;
        }
    }
    return (cnt);
}

void middle()
{
    int start = g_av_idx;
    g_prev_fd = g_fd[READ_END];
    pipe(g_fd);

    while (g_av[g_av_idx] && strncmp(g_av[g_av_idx], "|", 2) != 0)
    {
        ++g_av_idx;
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        close(g_fd[READ_END]);
        dup2(g_prev_fd, STDIN_FILENO);
        dup2(g_fd[WRITE_END], STDOUT_FILENO);
        g_av[g_av_idx] = NULL;
        execve(g_av[g_av_idx - 1], g_av + start, NULL);
    }
    else
    {
        close(g_fd[WRITE_END]);
        ++g_av_idx;
    }
}

void last()
{
    int start = g_av_idx;
    pid_t pid;
    pid = fork();

    // 자식
    if (pid == 0)
    {
        dup2(g_fd[READ_END], STDIN_FILENO);
        execve(g_av[g_av_idx], g_av + start, NULL);
    }
    else
    {
        close(g_fd[READ_END]);
    }
}

void first()
{
    int start = g_av_idx;
    pid_t pid;

    while (g_av[g_av_idx] && strncmp(g_av[g_av_idx], "|", 2) != 0)
    {
        ++g_av_idx;
    }

    pipe(g_fd);
    pid = fork();

    // 자식
    if (pid == 0)
    {
        close(g_fd[READ_END]);
        dup2(g_fd[WRITE_END], STDOUT_FILENO);
        g_av[g_av_idx] = NULL;
        // ["a.out", "ls", "|", "cat"]
        // ["ls", NULL, "cat"]
        execve(g_av[g_av_idx - 1], g_av + start, NULL);
        printf("FAIL\n");
    }
    else
    {
        close(g_fd[WRITE_END]);
        ++g_av_idx;
    }
}

void run_command()
{
    int pipe_cnt = get_pipe_cnt();
    if (pipe_cnt == 0)
    {
        if (strncmp(g_av[g_av_idx], "cd", 3) == 0)
        {
            cd();
        }
        else
        {
            int start = g_av_idx;
            pid_t pid;

            while (g_av[g_av_idx] && strncmp(g_av[g_av_idx], "|", 2) != 0)
            {
                ++g_av_idx;
            }
            pid = fork();

            // 자식
            if (pid == 0)
            {
                close(g_fd[READ_END]);
                dup2(g_fd[WRITE_END], STDOUT_FILENO);
                g_av[g_av_idx] = NULL;
                execve(g_av[g_av_idx - 1], g_av + start, NULL);
            }
            ++g_av_idx;
        }
    }
    else
    {
        for (; g_process_cnt <= pipe_cnt; g_process_cnt++)
        {
            if (g_process_cnt == 0)
            {
                first();
            }
            else if (g_process_cnt == pipe_cnt)
            {
                last();
            }
            else
            {
                middle();
            }
        }
    }
    for (int i = 0; i <= pipe_cnt; i++)
    {
        wait(NULL);
    }
}

int main(int ac, char *av[])
{
    g_ac = ac;
    g_av = av;
    if (g_ac == 1)
    {
        return (1);
    }
    int command_cnt = get_command_cnt();
    for (int i = 0; i < command_cnt; i++)
    {
        run_command();
        while (g_av[g_av_idx] && strncmp(g_av[g_av_idx], ";", 2) != 0)
        {
            ++g_av_idx;
        }
        ++g_av_idx;
    }
    return (0);
}
