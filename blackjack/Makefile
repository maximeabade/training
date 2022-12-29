CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm
RM = rm -f
srcdir = src/
bindir = bin/
docdir = doc/
savedir = save/
SRC = $(wildcard $(srcdir)*.c)
HEAD = $(wildcard *.h)
OBJ = $(subst $(srcdir), $(bindir), $(SRC:.c=.o))
EXEC = BLACKJACK

#Compilation
all : $(EXEC)

#Compile le programme
$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

#Compile les objetss
./bin/%.o : ./src/%.c 
	$(CC) $(CFLAGS) -c $^ -o $@
	
#Suppression les objets et la documentation
.PHONY : clean
clean : 
	$(RM) $(OBJ)
	rm -rf doc/html doc/latex
	mv $(EXEC) $(bindir)
	rm save/*


#Création de la documentation Doxygen
.PHONY : doc 
doc : 
	doxygen -g Doxyfile && doxygen Doxyfile
	mv Doxyfile html latex $(docdir)

#Ouverture de la docuementation Doxygen
.PHONY : doxy
doxy :
	firefox doc/html/index.html

#Sauvegarde des sources
.PHONY : save
save : 
	cp -r src/* $(savedir)

#Utilisation de la dernière sauvegarde
.PHONY : restore
restore :
	cp -r save/* $(srcdir)
