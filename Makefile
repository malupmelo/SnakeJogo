CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Ibiblioteca

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
BIBLIOTECA_DIR = biblioteca

SRCS = $(wildcard $(SRC_DIR)/*.c)
LIB_SRCS = $(wildcard $(BIBLIOTECA_DIR)/*.c)

SRC_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
LIB_OBJS = $(patsubst $(BIBLIOTECA_DIR)/%.c,$(BUILD_DIR)/%.o,$(LIB_SRCS))
OBJS = $(SRC_OBJS) $(LIB_OBJS)

EXEC = jogo_cobra

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(BIBLIOTECA_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(EXEC)

.PHONY: clean
