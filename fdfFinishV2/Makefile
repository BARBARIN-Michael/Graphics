#type du projet
#TYPE = algebre
TYPE = graphique

#Nom de lexecutable :
EXECUTABLE = fdf

# Choix du compilateur :
COMPILATEUR = gcc
#COMPILATEUR = perl ~/script/colorgcc.pl

# Options
COPTIONS = -g -O3 -Wall -Wextra -Werror

LIB  =  -I Lib/Includes -I Lib/libft/includes/  -L Lib/libft/  -lft
#LIB  += -I Lib/libft_obj/includes/  -L Lib/libft_obj/  -lftobj
#LIB  += -I Lib/libft_math/includes/ -L Lib/libft_math/ -lftmath

ifeq ($(TYPE), graphique)
	LIB  += -I /usr/X11/include -L Lib/minilibx/ -lmlx
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
SRCDIR = $(CODE)/Src
OBJDIR = $(CODE)/Objet
INCDIR = $(CODE)/Include

# creation de la liste des fichiers sources :
SRC =	$(SRCDIR)/ft_algofdf.c	\
		$(SRCDIR)/ft_fdf.c		\
		$(SRCDIR)/ft_graph.c	\
		$(SRCDIR)/ft_parse.c	\
		$(SRCDIR)/ft_list.c		\
		$(SRCDIR)/ft_math.c		\
		$(SRCDIR)/ft_mathline.c	\
		$(SRCDIR)/ft_event.c	\
		$(SRCDIR)/ft_map.c		\
		$(SRCDIR)/ft_color.c	\
		$(SRCDIR)/main.c		\
		$(SRCDIR)/ft_win.c		\
		$(SRCDIR)/get_next_line.c

# Liste des fichiers objets :
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(NOM)))

.PHONY: help

help:
	@echo
	@echo "\033[33;36m Programme ... "
	@echo "\033[33;36m--------------------------------------------------------------------------"
	@echo "\033[33;36m Regles disponibles"
	@echo
	@echo "\033[33;36m install   : \033[33;0mCreation des dossiers"
	@echo "\033[33;36m cp        : \033[33;0mcompilation et creation de l'executable"
	@echo "\033[33;36m re        : \033[33;0mReload du programme au complet"
	@echo "\033[33;36m clean     : \033[33;0mSupprime tout les fichier .o"
	@echo "\033[33;36m re        : \033[33;0mSupprime et recree les dossier Bin et Obj"
	@echo "\033[33;36m uninstall : \033[33;0mReset complet du dossier (sup. Bin, Obj)"
	@echo "\033[33;36m--------------------------------------------------------------------------"
	@echo

# -------------------------------------------------------------------
#  compilation
# -------------------------------------------------------------------

re_pre: faire_dossier cp

# regle pour fabriquer les dossiers;
faire_dossier: dirobj direxe
	@echo
	@echo "\033[33;32mFile created\tDONE\033[33;0m"
	@echo

# regle edition de liens
install: faire_dossier

cp: $(OBJ)
	@printf "\r\033[33;32mLinking $@, executable create\n\033[33;0m"
	@$(COMPILATEUR) $(COPTIONS) $(LIB) -o $(EXEDIR)/$(EXECUTABLE) $(OBJ)

# regle de compilation des sources
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\r\033[33;33mCompiling $<\n\033[33;0m"
	@$(COMPILATEUR) -c  $(COPTIONS) $(LIB) -I$(INCDIR) -o $@  $<

# -------------------------------------------------------------------
#  regles de creation des dossiers
# -------------------------------------------------------------------

.PHONY: dirobj direxe bin

# creation du dossier $(OBJDIR) si besoin :
ifeq (,$(wildcard $(OBJDIR)))
dirobj:
	mkdir -p $(OBJDIR)
endif

ifeq (,$(wildcard $(EXEDIR)))
direxe:
	mkdir -p $(EXEDIR)
	make -C ./Lib/libft/
endif

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
	make -C ./Lib/libft/ fclean

re: fclean cp
