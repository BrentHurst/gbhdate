# G BRENT HURST
# Makefile for gbhdate

LIBDIR = lib
OBJDIR = obj
SRCDIR = src
INCDIR = include
BINDIR = bin

CC = g++
CFLAGS = -Wall -Wextra -I$(INCDIR)


########## EDIT BELOW HERE ##########

NAME = gbhdate

########## EDIT ABOVE HERE ##########

LIB = $(LIBDIR)/lib$(NAME).a
LIBOBJ = $(OBJDIR)/$(NAME).o
MAINOBJ = $(OBJDIR)/tester.o
EXE = $(BINDIR)/tester_$(NAME).out
OBJECTS = $(LIBOBJ) $(MAINOBJ)


all: $(LIB) $(EXE)

$(EXE): $(MAINOBJ) $(LIB)
	$(CC) -o $@ $< -L$(LIBDIR) -l$(NAME)

$(LIB): $(LIBOBJ)
	ar -vr $@ $(LIBOBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(LIB) $(EXE)
