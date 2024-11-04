/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmdt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:57:00 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/04 15:57:01 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_cmdt  *ft_get_cmdt(t_dll *token_list)
{
   t_cmdt   *cmdt;

   cmdt = (t_cmdt *)malloc(sizeof(cmdt));
   ft_set_cmdt_type(cmdt, token_list);
   if (!cmdt->content && t_dll_size(token_list) == 0)
      return NULL;
   return (cmdt);
}
