VPATH=..
OBJ = diacrit.o e.o eqnbox.o font.o fromto.o funny.o glob.o integral.o \
	io.o lex.o lookup.o mark.o matrix.o move.o over.o paren.o pile.o \
	shift.o size.o sqrt.o text.o version.o

FLAGS = -I. -I..

.c.o:
	$(CC) $(CFLAGS) $(WARN) $(CPPFLAGS) $(FLAGS) -c $<

all: eqn

eqn: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LIBS) -o eqn

e.c: e.y
	$(YACC) -d ../e.y
	sed -f ../yyval.sed <y.tab.c >$@
	rm y.tab.c
	mv -f y.tab.h e.def

e.def: e.c

install:
	test -d $(ROOT)$(BINDIR) || mkdir -p $(ROOT)$(BINDIR)
	$(INSTALL) -c eqn $(ROOT)$(BINDIR)/eqn
	$(STRIP) $(ROOT)$(BINDIR)/eqn
	test -d $(ROOT)$(MANDIR)/man1b || mkdir -p $(ROOT)$(MANDIR)/man1b
	$(INSTALL) -c -m 644 eqn.1b $(ROOT)$(MANDIR)/man1b/eqn.1b

clean:
	rm -f $(OBJ) eqn e.c e.def core log *~

mrproper: clean

diacrit.o: ../diacrit.c ../e.h e.def
eqnbox.o: ../eqnbox.c ../e.h
font.o: ../font.c ../e.h
fromto.o: ../fromto.c ../e.h
funny.o: ../funny.c ../e.h e.def
glob.o: ../glob.c ../e.h
integral.o: ../integral.c ../e.h e.def
io.o: ../io.c ../e.h
lex.o: ../lex.c ../e.h e.def
lookup.o: ../lookup.c ../e.h e.def
mark.o: ../mark.c ../e.h
matrix.o: ../matrix.c ../e.h
move.o: ../move.c ../e.h e.def
over.o: ../over.c ../e.h
paren.o: ../paren.c ../e.h
pile.o: ../pile.c ../e.h
shift.o: ../shift.c ../e.h e.def
size.o: ../size.c ../e.h
sqrt.o: ../sqrt.c ../e.h
text.o: ../text.c ../e.h e.def
e.o: e.c ../e.h
