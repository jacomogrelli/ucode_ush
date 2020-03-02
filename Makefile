NAME	=	ush

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic) -g

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/$(INCD)

INC		=	ush.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		=	main.c \
			mx_errors_cd.c \
			mx_mystrsplit.c \
			mx_e_too_many_arg_cd.c \
			mx_printerr.c \
			mx_dirorfile.c \
			mx_e_no_dirorfile_cd.c \
			mx_e_notpwd_cd.c \
			mx_e_nodir_after_split_pwd_cd.c \
			mx_my_repl_substr_cd.c \
			mx_my_repl_substr.c \
			mx_errors_for_comands.c \
			mx_join_for_cd.c \
			mx_my_count_words.c \
			mx_change_pwd_in_cd.c \
			mx_parse_flags_cd.c \
			mx_ush_init.c \
			mx_get_command.c \
			mx_run_cd.c \
			mx_run_exit.c \
			mx_run_exec.c \
			mx_envp_pack.c \
			mx_run_cd_command.c \
			mx_cd_without_flags.c \
			mx_cd_with_flags.c \
			mx_pwd_run.c \
			mx_which_run.c \

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

$(FILE:a/%=%)

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)

clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall install
