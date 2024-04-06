NAME = minecrouft

CC = cc

CFLAGS = -g
IFLAGS = -Iinclude
LFLAGS = -Llib -lm -lGL -lGLU -lglfw

FILES =	main pos player chunk world textures keyboard minecrouft

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix obj/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $@ $(OBJS) $(LFLAGS)
	@echo "✔ Executable created."

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo Compiling $<...
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean :
	@rm -rf obj/

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re