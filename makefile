# G BRENT HURST
# Makefile for gbhdate

CC = g++
CFLAGS = -Wall -Wextra

########## EDIT BELOW HERE ##########

NAME = gbhdate

########## EDIT ABOVE HERE ##########

OBJDIR = obj
LIB = lib$(NAME).a
OBJECTS = $(OBJDIR)/$(NAME).o


all: $(LIB)

$(LIB): $(OBJECTS)
	ar -vr $@ $(OBJECTS)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(LIB)
