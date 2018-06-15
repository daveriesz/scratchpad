
PROGRAMS = drawf font image

CSOURCES = drawf.c font.c image.c
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

drawf: drawf.o
	@printf " + LD %$(STRLONG)s <== %$(STRLONG)s\n" "$@" "$^"
	@$(CC) -o $@ $^ $(LDFLAGS)
        
font: font.o
	@printf " + LD %$(STRLONG)s <== %$(STRLONG)s\n" "$@" "$^"
	@$(CC) -o $@ $^ $(LDFLAGS)
        
image: image.o
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
