NAME:= libasm.a

COMPILATOR:= nasm

OPTION:= -felf64

SRC_FILE:= ft_strlen.s ft_write.s ft_strcpy.s ft_strcmp.s ft_read.s ft_strdup.s

OBJ_FILE:= ${SRC_FILE:.s=.o}

LIBMAKER:= ar rc

${NAME}: ${OBJ_FILE}
	${LIBMAKER} ${NAME} ${OBJ_FILE}

all: ${NAME}

.s.o:
	${COMPLIATOR} ${OPTION} -o $@ $?
clean:
	rm -rf ${OBJ_FILE}

fclean: clean
	rm -rf ${NAME}
	rm -rf a.out
re: fclean all

.PHONY: all clean fclean re .s.o
