#ifndef FT_BUILT_INS_H
# define FT_BUILT_INS_H
# include "../../inc/minishell.h"

typedef struct minishell_obj	t_minishell;

void							set_env_var(t_minishell *minishell,
									const char *key, const char *value);
void							ft_cd(char **args, t_minishell *minishell);
void							ft_echo(char **args);
bool							ft_is_built_in(char *cmd, char **args,
									t_minishell *minishell);
void							ft_pwd(t_minishell *minishell);
void							ft_export(char **args, t_minishell *minishell);
void							print_env(t_dll *envs);
void							print_env_declare(t_dll *envs);
void							process_env_var(char *arg,
									t_minishell *minishell, t_dll **envs);
bool							check_valid_env_var(char *str);
char							*strndup(const char *s, size_t n);
void							sort_ascii(char **list, int size);
char							**create_aux_list(t_dll *envs, int size);
void							print_env(t_dll *envs);
void							ft_unset(char **args, t_minishell *minishell);
void							ft_exit(char **args, t_minishell *minishell);
#endif
