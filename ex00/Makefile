# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lsinke <lsinke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/23 19:36:26 by lsinke        #+#    #+#                  #
#    Updated: 2022/06/23 19:36:26 by lsinke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := ezfind

CC = c++

CFLAGS += -Wall -Werror -Wextra
CFLAGS += -std=c++98

SRCS :=	main.cpp

OBJD :=	obj/
OBJS :=	$(SRCS:.cpp=.o)
OBJP :=	$(addprefix $(OBJD), $(OBJS))

INCS :=	easyfind.hpp

all: $(NAME)

$(OBJD)%.o: %.cpp $(INCS)
	@mkdir -p $(@D)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJP)
	@echo "Compiling main executable"
	@$(CC) $(CFLAGS) $(OBJP) -o $(NAME)

clean:
	@rm -rf $(OBJD)
	@echo "Done cleaning $(CURDIR)/$(OBJD)"

fclean: clean
	@rm -f $(NAME)
	@echo "Done cleaning executable $(CURDIR)/$(NAME)"

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re