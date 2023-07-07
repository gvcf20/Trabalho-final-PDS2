SRCDIR := code
INCDIR := header
DEPDIR := Arquivos

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

DEPS := $(patsubst $(SRCDIR)/%.o, $(DEPDIR)/%.d, $(OBJS))

.PHONY: all clean

all: truco

truco: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@
	mv $(SRCDIR)/$*.d $(DEPDIR)/

-include $(DEPS)

run: truco
	./truco

clean:
	rm -f $(OBJS) $(DEPS) truco
