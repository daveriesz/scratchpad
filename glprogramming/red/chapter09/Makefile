
PROGRAMS = checker mipmap texgen

CSOURCES = checker.c mipmap.c texgen.c
COBJECTS = $(CSOURCES:.c=.o)
CFLAGS   = $(COPT) $(CDEF) $(CINC)
COPT     = 
CDEF     = 
CINC     = 

LDFLAGS  = $(LDDIR) $(LDLIB)
LDDIR    = 
LDLIB    = -lGL -lGLU -lglut

STRLONG  = 10

all: $(PROGRAMS)

checker: checker.o
	@printf " + LD %$(STRLONG)s <== %$(STRLONG)s\n" "$@" "$^"
	@$(CC) -o $@ $^ $(LDFLAGS)
        
mipmap: mipmap.o
	@printf " + LD %$(STRLONG)s <== %$(STRLONG)s\n" "$@" "$^"
	@$(CC) -o $@ $^ $(LDFLAGS)
        
texgen: texgen.o
	@printf " + LD %$(STRLONG)s <== %$(STRLONG)s\n" "$@" "$^"
	@$(CC) -o $@ $^ $(LDFLAGS)
        
%.o: %.c
	@printf " + CC %$(STRLONG)s <== %$(STRLONG)s\n" "$@" "$<"
	@$(CC) -o $@ -c $< $(CFLAGS)

run: $(PROGRAM)
	./$<

clean: objclean execlean

objclean:
	$(RM) -f $(COBJECTS)

execlean:
	$(RM) -f $(PROGRAMS)
