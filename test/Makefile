NAME = so_long.out

INC = includes

SRC = main.c

LIBX = minilibx

INCS = -I$(LIBX) -I$(INC)

LIBS = minilibx/libmlx.a -L$(LIBX) -lmlx

FLAGS = $(INCS) $(LIBS) -framework OpenGL -framework Appkit


all:
	@clear
	@echo -n Compiling Libs...
	@make -s -C $(LIBX)
	@echo Done
	@echo -n Compiling so_long...
	@gcc $(SRC) $(FLAGS) -o $(NAME)
	@echo Done

git:
	@clear
	@git add .
	@echo "commit msg" 
	@read COMMIT; \
	git commit -m "$$COMMIT"; \
	git push;

clean:
	@echo "     - Removing object files..." 
	@rm -rf $(OBJ)

fclean: clean
	@echo "     - Removing $(NAME)..." 
	@rm -rf $(NAME)

re: fclean all

bonus: all

norm:
	@clear
	@norminette $(INC) $(SRC) $(LIBALL)