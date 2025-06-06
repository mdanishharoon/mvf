CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -Iinclude
TARGET = mvf
SRC_DIR = src
INCLUDE_DIR = include
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/windows.c $(SRC_DIR)/transfer.c
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=%.o)
HEADERS = $(INCLUDE_DIR)/mvf.h
INSTALL_DIR = /usr/local/bin

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	@echo "Installing $(TARGET) to $(INSTALL_DIR)..."
	sudo cp $(TARGET) $(INSTALL_DIR)/
	sudo chmod +x $(INSTALL_DIR)/$(TARGET)
	@echo "✓ $(TARGET) successfully installed!"
	@echo "You can now use 'mvf' from anywhere in your system."

uninstall:
	@echo "Removing $(TARGET) from $(INSTALL_DIR)..."
	sudo rm -f $(INSTALL_DIR)/$(TARGET)
	@echo "✓ $(TARGET) successfully uninstalled!"

check:
	@echo "Checking if $(TARGET) is installed..."
	@if command -v $(TARGET) >/dev/null 2>&1; then \
		echo "✓ $(TARGET) is installed and available in PATH"; \
		echo "Location: $$(which $(TARGET))"; \
	else \
		echo "✗ $(TARGET) is not installed or not in PATH"; \
		echo "Run 'make install' to install it."; \
	fi

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: install uninstall clean check 