SRCDIR := code
INCDIR := header

CXX := g++
CXXFLAGS := -std=c++17

OBJS := $(SRCDIR)/main.o \
        $(SRCDIR)/embaralhamento.o \
        $(SRCDIR)/jogador.o \
        $(SRCDIR)/JOGO_principal.o \
        $(SRCDIR)/jogo.o \
        $(SRCDIR)/regras.o \
        $(SRCDIR)/rodada.o \
        $(SRCDIR)/sub_rodada.o

.PHONY: all clean

all: truco

truco: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: truco
	./truco

clean:
	rm -f $(SRCDIR)/*.o truco
