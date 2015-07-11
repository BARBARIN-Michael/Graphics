#type du projet
#TYPE = algebre
TYPE = graphique

#Nom de lexecutable :
EXECUTABLE = wolf3d
NAME = wolf3d

# Choix du compilateur :
COMPILATEUR = $(CC)
#COMPILATEUR = perl ~/script/colorgcc.pl

# Options
COPTIONS = -g -O0 -Wall -Wextra -Werror
COPTIONS = -g 

INC  =   -I Libs/libft/Include/
LIB  =   -L Libs/libft/ -lft -lm
#LIB  += -I Lib/libft_obj/includes/  -L Lib/libft_obj/  -lftobj
#LIB  += -I Lib/libft_math/includes/ -L Lib/libft_math/ -lftmath

ifeq ($(TYPE), graphique)
	LIB  += -framework OpenGL -framework AppKit -LLibs/minilibx_macos -lmlx
endif

# -------------------------------------------------------------------
#  Emplacement des sources et des objets, des includes et de lexecutable
# -------------------------------------------------------------------

# Dossier racine du code :
CODE :=.

# dossier de lexecutable
EXEDIR := $(CODE)/Bin

# Adresse des sources, des objets et des includes :
SRCDIR = $(CODE)/Srcs
OBJDIR = $(CODE)/Objets
INCDIR = $(CODE)/Includes

SRC =	$(SRCDIR)/ft_color.c		\
		$(SRCDIR)/ft_event.c		\
		$(SRCDIR)/ft_exec.c			\
		$(SRCDIR)/ft_action_key.c	\
		$(SRCDIR)/ft_action_key2.c	\
		$(SRCDIR)/ft_action_mouse.c	\
		$(SRCDIR)/ft_draw.c			\
		$(SRCDIR)/ft_engine.c		\
		$(SRCDIR)/ft_engine_tiles.c	\
		$(SRCDIR)/ft_error.c		\
		$(SRCDIR)/ft_init.c			\
		$(SRCDIR)/ft_mlx.c			\
		$(SRCDIR)/ft_movement.c		\
		$(SRCDIR)/ft_parse.c		\
		$(SRCDIR)/ft_setupfcts.c	\
		$(SRCDIR)/ft_tiles.c		\
		$(SRCDIR)/ft_graph.c		\
		$(SRCDIR)/ft_mapdesign.c	\
		$(SRCDIR)/main.c

# Liste des fichiers objets :
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(NOM)))

.PHONY: help

help:
	@echo
	@echo "\033[33;36m Programme \033[33;1m$(EXECUTABLE)\033[33;0m"
	@echo "\033[33;36m--------------------------------------------------------------------------"
	@echo "\033[33;36m Regles disponibles"
	@echo
	@echo "\033[33;36m install   : \033[33;0mCreation des dossiers"
	@echo "\033[33;36m relib     : \033[33;0mRecompile la library"
	@echo "\033[33;36m cplib     : \033[33;0mcompile la library"
	@echo "\033[33;36m cp        : \033[33;0mcompilation et creation de l'executable"
	@echo "\033[33;36m re        : \033[33;0mReload du programme au complet"
	@echo "\033[33;36m clean     : \033[33;0mSupprime tout les fichier .o"
	@echo "\033[33;36m re        : \033[33;0mSupprime et recree les dossier Bin et Obj"
	@echo "\033[33;36m uninstall : \033[33;0mReset complet du dossier (sup. Bin, Obj)"
	@echo "\033[33;36m launcher  : \033[33;0mLance l'executable"
	@echo "\033[33;36m--------------------------------------------------------------------------"
	@echo

# -------------------------------------------------------------------
#  compilation
# -------------------------------------------------------------------

.PHONY: install cp faire_dossier all

all: $(NAME)

# regle pour fabriquer les dossiers;
faire_dossier: dirobj direxe relib
	@echo
	@echo "\033[33;32mFile created\tDONE\033[33;0m"
	@echo

# regle edition de liens
install: faire_dossier re

$(NAME): $(OBJ)
	@printf "\r\033[33;32mLinking $@, executable create\n\033[33;0m"
	@$(COMPILATEUR) $(COPTIONS) -o $(EXEDIR)/$(EXECUTABLE) $(OBJ) $(LIB)
	@echo "\033[33;32m OK\033[33;0m"

# regle de compilation des sources
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\r\033[33;33mCompiling $<\n\033[33;0m"
	@$(COMPILATEUR) -c  $(COPTIONS) -I$(INCDIR) -o $@ $< $(INC)
	@echo "\033[33;32m OK\033[33;0m"

# -------------------------------------------------------------------
#  regles de creation des dossiers
# -------------------------------------------------------------------

.PHONY: dirobj direxe bin relib cplib launcher

# creation du dossier $(OBJDIR) si besoin :
dirobj:
	mkdir -p $(OBJDIR)
	mkdir -p $(INCDIR)
	mkdir -p $(SRCDIR)
	mkdir -p ./Libs/

direxe:
	mkdir -p $(EXEDIR)

relib:
	make -C ./Libs/libft/ re
	make -C ./Libs/minilibx_macos/ clean
	make -C ./Libs/minilibx_macos/

cplib:
	make -C ./Libs/libft/

launcher:
	./Bin/$(EXECUTABLE)

# -------------------------------------------------------------------
#  regles de nettoyage
# -------------------------------------------------------------------

.PHONY: clean fclean re

# pour effacer tous les objet :
clean:
	rm -rf $(OBJDIR)

# pour effacer tous les objet et les executables :
fclean: clean
	rm -rf $(EXEDIR) $(OBJDIR) && mkdir -p $(EXEDIR) $(OBJDIR)

uninstall:
	printf "\r\033[33;31mDelete all project file and library file\033[33;0m\n"
	rm -rf $(OBJDIR) $(EXEDIR)
	make -C ./Libs/libft/ fclean
	make -C ./Libs/minilibx_macos/ clean

re: fclean $(NAME)
