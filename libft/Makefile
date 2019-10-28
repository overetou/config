.PHONY : clean, fclean, all

NAME = libft.a

objdir = obj

obj = $(addprefix $(objdir)/, exit.o buff_basics.o file_length.o read_char_trigger.o fd_basics.o read_basic_travel.o wrap_open.o mem_assign.o pointer_basics.o simple_link_find.o int_compare.o meta.o tab_manipulation.o input.o simple_parsing.o put.o string_compare.o string_link_match.o string_basic.o string_find.o strtab_matching.o type_conversion.o type_question.o track_insert.o t_simple_basics.o trigger_init.o track_destroy.o read_word.o read_number.o int_to_str.o track_create.o str_to_float.o)

VPATH = src/directory_manipulation:src/file_manipulation:src/generic_manipulation:src/parsing:src/exit:src/int_manipulation:src/string_manipulation:src/type_manipulation:src/lists

CC = gcc

CFLAGS = -Wextra -Werror -Wall -I header/

$(objdir)/%.o : %.c
	@$(COMPILE.c) $(OUTPUT_OPTION) $<

all: $(NAME)

$(NAME): $(obj)
	@ar rc $@ $^
	@ranlib $@

$(obj): | $(objdir)

$(objdir):
	mkdir $(objdir)

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@$(CC) test_main.c -I header/ ./$(NAME)
	@./a.out

