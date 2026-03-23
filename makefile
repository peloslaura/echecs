CPPFILES = \
	echiquier.cpp \
	jeu.cpp \
	main.cpp \
	piece.cpp \
	pieces/cavalier.cpp \
	pieces/dame.cpp \
	pieces/fou.cpp \
	pieces/pion.cpp \
	pieces/roi.cpp \
	pieces/tour.cpp \

SRCDIR = src
SOURCES = $(foreach file, $(CPPFILES), $(SRCDIR)/$(file))
INCLUDE = -Iinclude
OBJDIR = build/obj
OFILES = $(CPPFILES:.cpp=.o)
SUBDIRS = pieces
TARGETS = $(foreach file, $(OFILES), $(OBJDIR)/$(file))
EXECDIR = build/target
EXECNAME = echecs
EXEC = $(EXECDIR)/$(EXECNAME)
GXX = g++

FLAGS=-g -Wall -Wextra -Wvla -pedantic -fsanitize=address,undefined -pthread
POSTFLAGS=-lm

debug=0
ifeq ($(debug),1)
FLAGS += -DDEBUG
else
FLAGS += -Werror
endif

$(shell mkdir -p $(OBJDIR))
$(shell mkdir -p $(EXECDIR))
$(foreach dir, $(SUBDIRS), $(shell mkdir -p $(OBJDIR)/$(dir)))


# Rule to generate object files from source files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(GXX) $(FLAGS) $(INCLUDE) -c $< -o $@

# The final target depends on all object files
$(EXEC): $(TARGETS)
	$(GXX) $(FLAGS) $(INCLUDE) -o $(EXEC) $(TARGETS) $(POSTFLAGS)


# Clean rule
clean:
	rm -rf $(EXEC) $(OBJDIR);
