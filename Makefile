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
			mx_set_correct_path.c \
			mx_run_echo_command.c \
			mx_print_e_for_echo.c \
			mx_pwd_run.c \
			mx_which_run.c \
			mx_which_helper.c \
			mx_envp_i.c \
			mx_unset_run.c \
			mx_save_story.c \
			mx_count_numbers.c \
			mx_envp_manage.c \
			mx_export_run.c \
			mx_env_run.c \
			mx_env_func.c \
			mx_parser.c \
			mx_ush_rescleaner.c \
			mx_handling_signals.c \
			mx_parcer_iline.c \
			mx_uniq_prompt.c \
			mx_true_false.c \
			mx_help_command.c \
			mx_return_command.c \
			mx_chdir_command.c \
			mx_appropos_command.c \
			mx_arch_command.c \
			mx_parser_tilda.c \
			mx_main_parse.c \
			mx_ignore_symb.c \
			mx_second_parse.c \
			mx_parser_var.c \
			mx_parser_array.c \
			mx_env_flags.c \
			mx_env_main.c \
			mx_change_var.c \
			mx_buffer_for_ignored_symb.c \
			mx_pwd_replace.c \
			mx_aud_for_ignore.c \
			mx_aud_for_vars.c \

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: $(LMXD) $(NAME)

$(FILE:a/%=%)

#install: $(LMXA) $(NAME)

$(NAME): $(LMXA) $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXD): $(LMXA)

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

reinstall: uninstall all
