# Diretórios
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INCLUDE_DIR := include

# Nome do executável
EXEC := tp3.out

# Lista de arquivos fonte e objeto
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Compilador e flags
CXX := g++
CXXFLAGS := -Wall -Wextra -I$(INCLUDE_DIR) -std=c++17
LDFLAGS :=

# Regra padrão
all: $(BIN_DIR)/$(EXEC)

# Regra para criar o executável
$(BIN_DIR)/$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

# Regra para compilar arquivos fonte em arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar arquivos gerados
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC)

# Regra para remover todos os arquivos gerados
distclean: clean
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean distclean

