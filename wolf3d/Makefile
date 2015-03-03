#type du projet
#TYPE = algebre
TYPE = graphique

#Nom de lexecutable :
EXECUTABLE = fractol

# Choix du compilateur :
COMPILATEUR = gcc
#COMPILATEUR = perl ~/script/colorgcc.pl

# Options
COPTIONS = -g -std=c99 -O0 -Wall -Wextra -Werror

LIB  =  -I Libs/minilibx -I Libs/libft/Include/  -L Libs/libft/ -lft
LIB  +=  -I Libs/libftprintf/Include/  -L Libs/libftprintf/  -lftprintf
#LIB  += -I Lib/libft_obj/includes/  -L Lib/libft_obj/  -lftobj
#LIB  += -I Lib/libft_math/includes/ -L Lib/libft_math/ -lftmath

ifeq ($(TYPE), graphique)
	LIB  += -I /usr/X11/include -L Libs/minilibx/ -lmlx
	LIB  += -L /usr/X11/lib/ -lXext -lX11 -lm
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

# creation de la liste des fichiers sources :
SRC =	$(SRCDIR)/ft_color.c		\
		$(SRCDIR)/ft_event.c		\
		$(SRCDIR)/ft_exec.c			\
		$(SRCDIR)/ft_fractal.c		\
		$(SRCDIR)/ft_graph.c		\
		$(SRCDIR)/ft_mandelbrot.c	\
		$(SRCDIR)/main.c

# Liste des fichiers objets :
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(NOM)))

.PHONY: help

help:
	@echo
	@echo -e "\033[33;36m Programme \033[33;1m$(EXECUTABLE)\033[33;0m"
	@echo -e "\033[33;36m--------------------------------------------------------------------------"
	@echo -e "\033[33;36m Regles disponibles"
	@echo
	@echo -e "\033[33;36m install   : \033[33;0mCreation des dossiers"
	@echo -e "\033[33;36m relib     : \033[33;0mRecompile la library"
	@echo -e "\033[33;36m cplib     : \033[33;0mcompile la library"
	@echo -e "\033[33;36m cp        : \033[33;0mcompilation et creation de l'executable"
	@echo -e "\033[33;36m re        : \033[33;0mReload du programme au complet"
	@echo -e "\033[33;36m clean     : \033[33;0mSupprime tout les fichier .o"
	@echo -e "\033[33;36m re        : \033[33;0mSupprime et recree les dossier Bin et Obj"
	@echo -e "\033[33;36m uninstall : \033[33;0mReset complet du dossier (sup. Bin, Obj)"
	@echo -e "\033[33;36m--------------------------------------------------------------------------"
	@echo

# -------------------------------------------------------------------
#  compilation
# -------------------------------------------------------------------

re_pre: faire_dossier cp

# regle pour fabriquer les dossiers;
faire_dossier: dirobj direxe
	@echo
	@echo -e "\033[33;32mFile created\tDONE\033[33;0m"
	@echo

# regle edition de liens
install: faire_dossier

cp: $(OBJ)
	@printf "\r\033[33;32mLinking $@, executable create\n\033[33;0m"
	$(COMPILATEUR) $(COPTIONS) -o $(EXEDIR)/$(EXECUTABLE) $(OBJ) $(LIB)

# regle de compilation des sources
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\r\033[33;33mCompiling $<\n\033[33;0m"
	$(COMPILATEUR) -c  $(COPTIONS) -I$(INCDIR) -o $@ $< $(LIB)

# -------------------------------------------------------------------
#  regles de creation des dossiers
# -------------------------------------------------------------------

.PHONY: dirobj direxe bin

# creation du dossier $(OBJDIR) si besoin :
dirobj:
	mkdir -p $(OBJDIR)
	mkdir -p $(INCDIR)
	mkdir -p $(SRCDIR)
	mkdir -p ./Libs/

direxe:
	mkdir -p $(EXEDIR)
	make -C ./Libs/libft/

relib:
	make -C ./Libs/libft/ re
	make -C ./Libs/minilibx/ re

cplib:
	make -C ./Libs/libft/

# -------------------------------------------------------------------
#  regles de nettoyage
# -------------------------------------------------------------------

.PHONY: clean fclean re

# pour effacer tous les objet :
clean:
	@rm -rf $(OBJDIR)

# pour effacer tous les objet et les executables :
fclean: clean
	rm -rf $(EXEDIR) $(OBJDIR) && mkdir -p $(EXEDIR) $(OBJDIR)

uninstall:
	@printf "\r\033[33;31mDelete all project file and library file\033[33;0m\n"
	rm -rf $(OBJDIR) $(EXEDIR)
	make -C ./Libs/libft/ fclean

re: fclean cp
