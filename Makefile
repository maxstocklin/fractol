#Compilation setting

NAME=fract-ol
CC=gcc
CFLAGS= -Wall -Wextra -Werror 
##-fsanitize=address

#Sources
DIR_SRC=./sources
SRCS=	${DIR_SRC}/main.c ${DIR_SRC}/init.c ${DIR_SRC}/zoom.c ${DIR_SRC}/draw.c ${DIR_SRC}/fractals.c ${DIR_SRC}/hooks.c ${DIR_SRC}/exit.c


DIR_OBJ=./objs
OBJS=${addprefix ${DIR_OBJ}/, ${notdir ${SRCS:.c=.o}}}

#Find the os
UNAME_S := $(shell uname -s)

#Linux
#$(CC)
#$(OBJS) -L${DIR_LIB_MLX}/ -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
ifeq ($(UNAME_S),Linux)
		DIR_LIB_MLX= ./mlx-linux
		DIR_LIB_SYS= ./usr/lib
		OFLAGS=-L${DIR_LIB_MLX} -lmlx  -I${DIR_LIB_MLX} -lXext -lX11 -lm -lz
endif
#L/usr/lib

#Apple
#$(CC) $(OBJS)		 -L${DIR_LIB_MLX}/ -Imlx -lmlx -o $(NAME)
#$(CC) $(OBJS) -L${DIR_LIB_M	LX}/ -Imlx-apple -lmlx -o $(NAME)

ifeq ($(UNAME_S),Darwin)
		DIR_LIB_MLX=mlx
		OFLAGS=-L${DIR_LIB_MLX} -lmlx -framework OpenGL -framework AppKit
endif

vpath %.c ${DIR_SRC}
RM=rm -f

all : ${NAME}
	@echo "                                                                                     "
	@echo "                                                                                     "
	@echo "                                                                                     "
	@echo "                                        .o.                                          "
	@echo "                                      o8888o                                         "
	@echo "                                     d888888b                                        "
	@echo "                                     Y8888888Y                                       "
	@echo "                                 o .oood88booo. .o                                   "
	@echo "                           Ybo  .88888888888888888.                                  "
	@echo "                            8888888888888888888888888b,                              "
	@echo "                          .o88888888888888888888888888                               "
	@echo "                        Y88888888888888888888888888888b.                             "
	@echo "                       .o8888888888888888888888888888888.                            "
	@echo "                       8888888888888888888888888888888888                            "
	@echo "        o, ,db, ,o    d8888888888888888888888888888888888                            "
	@echo "       .8888888888.   88888888888888888888888888888888888                            "
	@echo "      o888888888888b  88888888888888888888888888888888888                            "
	@echo "     d88888888888888o88888888888888888888888888888888888P                            "
	@echo " .o8o88888888888888888888888888888888888888888888888888Y                             "
	@echo "<8888888888888888888888888888888888888888888888888888K                               "
	@echo "  YI88888888888888888888888888888888888888888888888888o                              "
	@echo "     Y88888888888888888888888888888888888888888888888888b                            "
	@echo "       888888888888   88888888888888888888888888888888888                            "
	@echo "        8888888888    88888888888888888888888888888888888                            "
	@echo "           IYPY       Y8888888888888888888888888888888888                            "
	@echo "                        888888888888888888888888888888888                            "
	@echo "                        Y8888888888888888888888888888888                             "
	@echo "                         88888888888888888888888888888P                              "
	@echo "                            88888888888888888888888888o                              "
	@echo "                            8888888888888888888888888P                               "
	@echo "                           dPY  Y88888888888888888                                   "
	@echo "                                 Y88888888P888888Y                                   "
	@echo "                                     88888888                                        "
	@echo "                                     Y888888P      	                                "
	@echo "                                      "8888"                                         "
	@echo "                                         Y                                           "
	@echo "                                                                                     "
	@echo "                                                                                     "
	@echo "                                                                                     "
	@echo "                                                                                     "
	@echo "                                                                                     "
	@echo "		███████╗██████╗  █████╗  ██████╗████████╗ ██████╗ ██╗                           "
	@echo "		██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██║                           "
	@echo "		█████╗  ██████╔╝███████║██║        ██║   ██║   ██║██║                           "
	@echo "		██╔══╝  ██╔══██╗██╔══██║██║        ██║   ██║   ██║██║                           "
	@echo "		██║     ██║  ██║██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗                      "
	@echo "		╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝                      "
	@echo "                                                                                     "
	@echo "                                                                                     "
	@echo "██████╗ ██╗   ██╗    ███╗   ███╗███████╗████████╗ ██████╗  ██████╗██╗  ██╗██╗     ██╗"
	@echo "██╔══██╗╚██╗ ██╔╝    ████╗ ████║██╔════╝╚══██╔══╝██╔═══██╗██╔════╝██║ ██╔╝██║     ██║"
	@echo "██████╔╝ ╚████╔╝     ██╔████╔██║███████╗   ██║   ██║   ██║██║     █████╔╝ ██║     ██║"
	@echo "██╔══██╗  ╚██╔╝      ██║╚██╔╝██║╚════██║   ██║   ██║   ██║██║     ██╔═██╗ ██║     ██║"
	@echo "██████╔╝   ██║       ██║ ╚═╝ ██║███████║   ██║   ╚██████╔╝╚██████╗██║  ██╗███████╗██║"
	@echo "╚═════╝    ╚═╝       ╚═╝     ╚═╝╚══════╝   ╚═╝    ╚═════╝  ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝"
	@echo "                                                                                     "
	@echo "                                                                                     "
	@echo "             Run the program and specify the fractal you want to see                 "
	@echo "                        (e.g.: "./fract-ol Mandelbrot")                              "
	@echo "                                                                                     "
	@echo "                                                                                     "
	@echo " Functionalities:                                                                    "
	@echo " You can zoom using the mouse scroll and the '-' and '+' keys                        "
	@echo " You can move around using arrow keys                                                "
	@echo " You can change colors by pressing the space key                                     "
	@echo " You can quit the program by pressing the escape key                                 "
	@echo "                                                                                     "

$(NAME):			 $(OBJS)
		#make -C ${DIR_LIB_MLX}
		$(CC) $(OBJS) -L${DIR_LIB_MLX} ${OFLAGS} -o $(NAME)

${DIR_OBJ}/%.o : %.c | ${DIR_OBJ}
		$(CC) ${CFLAGS} -I${DIR_LIB_MLX} -O3 -c $< -o $@

${DIR_OBJ} :
		@mkdir -p ${DIR_OBJ}

clean:
		#make clean -C ${DIR_LIB_MLX}
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME} 

re: fclean all
		#make re -C ${DIR_LIB_MLX}

.PHONY:		all clean fclean re

norm:
		norminette ${SRCS} 