# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 13:10:51 by ilbonnev          #+#    #+#              #
#    Updated: 2024/12/10 13:53:17 by ilbonnev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c ft_isalnum.c   \
			ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c       \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c    \
			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c     \
			ft_memcmp.c ft_strnstr.c ft_iswsp.c ft_atoi.c ft_calloc.c          \
			ft_strdup.c														   \
																			   \
			ft_substr.c ft_strjoin.c ft_isinset.c ft_getword.c ft_strtrim.c	   \
			ft_countwords.c ft_split.c ft_abs.c ft_countdigits.c ft_itoa.c	   \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c 		   \
			ft_putendl_fd.c ft_putnbr_fd.c ft_checkextension.c ft_strcat.c	   \
			ft_nbrow.c

BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c 	   \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c     \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS	=	$(SRCS:.c=.o)

BONUS_O	=	$(BONUS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(BONUS_O)
			ar rcs $(NAME) $(OBJS) $(BONUS_O)

clean:
			rm -f $(OBJS) $(BONUS_O)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus