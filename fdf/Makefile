#Nom de lexecutable :
EXECUTABLE = prog.mlx

# Choix du compilateur :
COMPILATEUR = gcc

# Options
COPTIONS = -O3 -Wall -Wextra -Werror

LSTD = -I Lib/Includes -L Lib/libft/ -lft
LMLX = -L Lib/minilibx/ -Lmlx
LX   = -L /usr/lib/ -lXext -lX11 -lm

LOPTION = $(basename $(LSTD) $(LMLX))
LOPTIONS = $(basename $(LOPTION) $(LX))
#OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(NOM)))
#	@echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
#	@echo "Creation des option de compilation libStd, libMlx, libX11"
#	@echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
#	@echo
# -------------------------------------------------------------------
#  Emplacement des sources et des objets, des includes et de lexecutable
# -------------------------------------------------------------------

# Dossier racine du code :
CODE := $(shell pwd)

# dossier de lexecutable
EXEDIR := $(CODE)/Bin

# Adresse des sources, des objets et des includes :
SRCDIR = $(CODE)/Src
OBJDIR = $(CODE)/Objet
INCDIR = $(CODE)/Include

# creation de la liste des fichiers sources :
SRC = $(wildcard $(SRCDIR)/*.c)

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
	@echo " Programme ... "
	@echo "--------------------------------------------------------------------------"
	@echo " Regles disponnibles"
	@echo
	@echo " install : compilation et creation de lexecutable"
	@echo " clean   : effacement des fichiers objets"
	@echo " purge   : effacement des fichiers objets et des executables"
	@echo " help    : affiche ces commentaires (defaut)"
	@echo "--------------------------------------------------------------------------"
	@echo

# -------------------------------------------------------------------
#  compilation
# -------------------------------------------------------------------

# regle pour fabriquer les dossiers;
faire_dossier: dirobj direxe
	@echo
	@echo "dossiers crees"
	@echo

# regle edition de liens
install: faire_dossier $(OBJ) 
	$(COMPILATEUR) $(LOPTIONS) -o $(EXEDIR)/$(EXECUTABLE) $(OBJ)

cp: $(OBJ)
	$(COMPILATEUR) $(LOPTIONS) -o $(EXEDIR)/$(EXECUTABLE) $(OBJ)

# regle de compilation des sources
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(COMPILATEUR) $(LOPTIONS) -c $(COPTIONS) -I$(INCDIR) -o $@ $<

# -------------------------------------------------------------------
#  regles de creation des dossiers 
# -------------------------------------------------------------------

.PHONY: dirobj direxe bin

# creation du dossier $(OBJDIR) si besoin :
#ifeq ("$(wildcard $(OBJDIR))","")
ifeq ("$(OBJDIR)", "")
dirobj:
	mkdir $(OBJDIR) || echo "" 2> /dev/null
else
dirobj:
	@echo "File /Objet alredy exists"
endif

# test si $(CODE)/bin existe et le cree si non
ifeq ("$(EXEDIR)", "")
direxe:
	mkdir $(EXEDIR) || echo "" 2> /dev/null
else
direxe:
	@echo "File /Bin already exists"
endif 

# -------------------------------------------------------------------
#  regles de nettoyage
# -------------------------------------------------------------------

.PHONY: clean purge

# pour effacer tous les objet :
clean:
	@rm -rv $(OBJDIR)

# pour effacer tous les objet et les executables :
fclean:
	@rm -rv $(OBJDIR) $(CODE)/Bin

# ------------------------------------------------
# $@ 		Le nom de la cible
# $<Le nom de		 la premiÃ¨re dÃ©pendance
# $^La liste des dÃ©pendances
# shell				pour executer une commande
# wildecardequivalent de * dans le termin	al
# basenameprend le nom sans le .c ou .o ...
# notdirsupprime le ch		emin devant un fichier
# stripsupprime les blancs => ifeq( $(strip $(		VAR) ) , ) = si $(VAR) est vide
# ------------------------------------------------

