NAME = so_long

NAME1 = so_long_bonus

CC = CC

CFLAGS = -Wall -Wextra -Werror

SRC = check_av_map.c\
	check_map_valid.c\
	check_map_valid1.c\
	so_long.c\
	split.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	flood.c\
	for_draw.c\
	moves.c\

SRC_BONUS = check_av_map_bonus.c\
			check_map_valid1_bonus.c\
			check_map_valid_bonus.c\
			fire_test_bonus.c\
			flood_bonus.c\
			for_draw_bonus.c\
			itoa_bonus.c\
			moves_bonus.c\
			so_long_bonus.c\
			split_bonus.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\

OBJS = $(SRC:.c=.o)

BONUSOBJS = $(SRC_BONUS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all : $(NAME)

bonus : $(NAME1)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME1) : $(BONUSOBJS)
	$(CC) $(CFLAGS) $(BONUSOBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME1)

clean :
	rm -rf $(OBJS) $(BONUSOBJS)

fclean : clean
	rm -rf $(NAME) $(NAME1)

re : fclean all bonus
