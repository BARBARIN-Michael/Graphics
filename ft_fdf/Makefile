#Nom de lexecutable :
EXECUTABLE = prog.mlx

# Choix du compilateur :
COMPILATEUR = gcc
#COMPILATEUR = perl ~/script/colorgcc.pl

# Options
COPTIONS = -g -O3 #-Wall -Wextra -Werror


LSTD = -I Lib/Includes -L Lib/libft/ -lft
LMLX = -L Lib/minilibx/ -lmlx
LX   = -L /usr/X11/lib/ -lXext -lX11 -lm

LOPTION = $(basename $(LSTD) $(LMLX))
LOPTIONS = $(basename $(LOPTION) $(LX))
#OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(NOM)))
#	@echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
#	@echo "Creation des option de compilation libStd, libMlx, libX11"
#	@echo LOPTIONS 
#	@echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
#	@echo
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
		$(SRCDIR)/main.c		\
		$(SRCDIR)/get_next_line.c

#SRC = $(wildcard $(SRCDIR)/*.c))

# Liste des fichiers objets :
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(NOM)))


#-------------------------------------------------------------------
#  regle par defaut = aide
#  @ evite dafficher la commande avant de lexecuter
# -------------------------------------------------------------------

.PHONY: help

help:
	@echo
	@echo "\033[33;36m Programme ... "
	@echo "\033[33;36m--------------------------------------------------------------------------"
	@echo "\033[33;36m Regles disponibles"
	@echo
	@echo "\033[33;36m install : \033[33;0mCreation des dossiers"
	@echo "\033[33;36m cp      : \033[33;0mcompilation et creation de l'executable"
	@echo "\033[33;36m clean   : \033[33;0meffacement des fichiers objets"
	@echo "\033[33;36m fclean  : \033[33;0meffacement des fichiers objets et des executables"
	@echo "\033[33;36m re      : \033[33;0mReload du programme au complet"
	@echo "\033[33;36m help    : \033[33;0maffiche ces commentaires (defaut)"
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
	$(COMPILATEUR) $(COPTIONS) $(LOPTIONS) -o $(EXEDIR)/$(EXECUTABLE) $(OBJ) 

# regle de compilation des sources
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(COMPILATEUR) -c  $(COPTIONS) $(LOPTIONS) -I$(INCDIR) -o $@  $<

# -------------------------------------------------------------------
#  regles de creation des dossiers 
# -------------------------------------------------------------------

.PHONY: dirobj direxe bin

# creation du dossier $(OBJDIR) si besoin :
ifeq (,$(wildcard $(OBJDIR)))
dirobj:
	mkdir $(OBJDIR)
else
dirobj:
	@echo "\033[33;32mFile /Objet alredy exists\033[33;0m"
endif

# test si $(CODE)/bin existe et le cree si non
ifeq (,$(wildcard $(EXEDIR)))
direxe:
	mkdir $(EXEDIR)
else
direxe:
	@echo "\033[33;32mFile /Bin already exists\033[33;0m"
endif 

# -------------------------------------------------------------------
#  regles de nettoyage
# -------------------------------------------------------------------

.PHONY: clean fclean re

# pour effacer tous les objet :
clean:
	@rm -rv $(OBJDIR)

# pour effacer tous les objet et les executables :
fclean:
	rm -rf $(OBJDIR) $(EXEDIR)

re: fclean dirobj direxe install cp



