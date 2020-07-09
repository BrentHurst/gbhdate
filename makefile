# G BRENT HURST
# Makefile for gbhdate

LIBDIR = lib
OBJDIR = obj
SRCDIR = src
INCDIR = include

CC = g++
CFLAGS = -Wall -Wextra -I$(INCDIR)


########## EDIT BELOW HERE ##########

NAME = gbhdate

########## EDIT ABOVE HERE ##########

LIB = $(LIBDIR)/lib$(NAME).a
OBJECTS = $(OBJDIR)/$(NAME).o


all: $(LIB)

$(LIB): $(OBJECTS)
	ar -vr $@ $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(LIB)
