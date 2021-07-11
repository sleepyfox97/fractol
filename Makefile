_RED	=	\033[31m
_GREAN	=	\033[32m
_YELLOW	=	\033[33m
_BLUE	=	\033[34m
_END	=	\033[0m

NAME	=	fractol
NAMEB	=	fractol_bonus

SRCS	=	srcs/main.c
SRCS	+=	srcs/error.c
SRCS	+=	srcs/event.c
SRCS	+=	srcs/draw_img.c
SRCS	+=	srcs/julia.c
SRCS	+=	srcs/mandelbrot.c
SRCS	+=	srcs/util_1.c
SRCS	+=	srcs/util_2.c

OBJS = $(SRCS:.c=.o)

SRCB	=	srcs/main.c
SRCB	+=	srcs/error.c
SRCB	+=	srcs/event_bonus.c
SRCB	+=	srcs/draw_img.c
SRCB	+=	srcs/julia.c
SRCB	+=	srcs/mandelbrot.c
SRCB	+=	srcs/util_1.c
SRCB	+=	srcs/util_2.c

OBJB = $(SRCB:.c=.o)

CC	= gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJB) -o $(NAME) -I./include -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm
	@echo "\nFINISH Compiling $(NAME)!"
	@echo "$(_YELLOW)Try \"./$(NAME)  rt_files/*.rt\" to use$(_END)"

$(NAMEB) : $(OBJB)
	@$(CC) $(CFLAGS) $(OBJB) -o $(NAMEB) -I./include -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm
	@echo "\nFINISH Compiling $(NAMEB)!"
	@echo "$(_YELLOW)Try \"./$(NAMEB)  rt_files/*.rt\" to use$(_END)"

clean:
	@echo "Removing object files...."
	@rm -rf $(OBJS) $(OBJB)

fclean:
	@echo "$(_RED)Removing object files and program....$(_END)"
	@rm -rf $(NAME) $(NAMEB) $(OBJS) $(OBJB)

re: fclean all

bonus: $(NAMEB)

%.o: %.c
	@$(CC) -c $(CFLAGS) -I./include -L./minilibx_linux -lmlx_Linux -lXext -lX11 -lm -o $@ $<
	@printf "$(_GREAN)>$(_END)"

PHONY: all clean fclean re bonus