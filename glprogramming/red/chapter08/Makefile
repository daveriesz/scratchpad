
PROGRAM = drawf

CSOURCES = drawf.c
COBJECTS = $(CSOURCES:.c=.o)
CFLAGS   = $(COPT) $(CDEF) $(CINC)
COPT     = 
CDEF     = 
CINC     = 

LDFLAGS  = $(LDDIR) $(LDLIB)
LDDIR    = 
LDLIB    = -lGL -lglut

STRLONG = 10

all: $(PROGRAM)

$(PROGRAM): $(COBJECTS)
	@printf " + LD %$(STRLONG)s <== %$(STRLONG)s\n" "$@" "..."
	@$(CC) -o $@ $^ $(LDFLAGS)
        
%.o: %.c
	@printf " + CC %$(STRLONG)s <== %$(STRLONG)s\n" "$@" "$<"
	@$(CC) -o $@ -c $< $(CFLAGS)

run: $(PROGRAM)
	./$<
