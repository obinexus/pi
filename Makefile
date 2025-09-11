# OBINexus π-Engine Makefile
# Forensic Computation of π as Proof of Infinite Accountability

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O3 -I./include
LDFLAGS = -lm
TARGET = obinexus_pi

# Directories
SRCDIR = src
INCDIR = include
LEGALDIR = legal
DESIGNDIR = design
BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj
BINDIR = $(BUILDDIR)/bin

# Source and object files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
HEADERS = $(wildcard $(INCDIR)/*.h)

# Executable path
EXECUTABLE = $(BINDIR)/$(TARGET)

.PHONY: all build run legal design clean install uninstall

all: build

# Create directory structure
$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(DESIGNDIR):
	@mkdir -p $(DESIGNDIR)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link executable
$(EXECUTABLE): $(OBJS) | $(BINDIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Convenience target
build: $(EXECUTABLE)

# Run the engine
run: build
	@echo "----- [OBINexus π] Mathematical Justice Engine -----"
	@$(EXECUTABLE)

# Generate legal claim
legal: build | $(DESIGNDIR)
	@echo "----- [OBINexus π] Legal Claim Generation -----"
	@$(EXECUTABLE) -l > $(LEGALDIR)/manifest.tmp
	@echo "# Claim $(shell date +%Y%m%d_%H%M%S)" > $(LEGALDIR)/CLAIM_$(shell date +%Y%m%d_%H%M%S).md
	@echo "## Forensic Data" >> $(LEGALDIR)/CLAIM_$(shell date +%Y%m%d_%H%M%S).md
	@cat $(LEGALDIR)/manifest.tmp >> $(LEGALDIR)/CLAIM_$(shell date +%Y%m%d_%H%M%S).md
	@rm -f $(LEGALDIR)/manifest.tmp
	@echo "[+] Claim generated: $(LEGALDIR)/CLAIM_$(shell date +%Y%m%d_%H%M%S).md"

# Generate Nsibidi design
design: build | $(DESIGNDIR)
	@echo "----- [OBINexus π] Nsibidi Seal Generation -----"
	@$(EXECUTABLE) -d > $(DESIGNDIR)/pi_seal_$(shell date +%Y%m%d).txt
	@echo "[+] Design generated: $(DESIGNDIR)/pi_seal_$(shell date +%Y%m%d).txt"

# Clean all build artifacts
clean:
	@rm -rf $(BUILDDIR)
	@rm -f $(LEGALDIR)/CLAIM_*.md
	@rm -f $(DESIGNDIR)/*.txt
	@echo "[+] Build artifacts cleaned"

# Install to system
install: build
	@sudo cp $(EXECUTABLE) /usr/local/bin/$(TARGET)
	@echo "[+] Installed to /usr/local/bin/$(TARGET)"

# Uninstall from system
uninstall:
	@sudo rm -f /usr/local/bin/$(TARGET)
	@echo "[+] Uninstalled from system"

# Development helpers
.PHONY: debug release

debug: CFLAGS += -g -O0 -DDEBUG
debug: clean build

release: CFLAGS += -O3 -DNDEBUG
release: clean build
