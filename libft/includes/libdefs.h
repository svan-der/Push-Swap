/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libdefs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-der <svan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/12 15:35:26 by svan-der       #+#    #+#                */
/*   Updated: 2019/12/23 10:01:21 by svan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDEFS_H
# define LIBDEFS_H
# include <string.h>
# define HEX "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define TRUE 1
# define FALSE 0
# define MAX_UINT -1U
# define MAX_SIZE_T -1UL
# define MAX_INT -1U / 2
# define MIN_INT -MAX_INT - 1

typedef unsigned long long			t_ull;
typedef unsigned char				t_byte;
typedef long double					t_ldb;
typedef long long					t_llong;
typedef unsigned int				t_uint;
typedef unsigned long int			t_ulong;
typedef unsigned short				t_ushort;
typedef __uint8_t					t_uchar;
typedef __uint128_t					t_u128;
typedef __int128_t					t_i128;
typedef long double					t_ldbl;
#endif
