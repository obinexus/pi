# OBINexus π-Engine Makefile
# Forensic Computation of π as Proof of Infinite Accountability

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O3 -I./include
LDFLAGS = -lm
TARGET = obinexus_pi
SRCDIR = src
INCDIR = include
LEGALDIR = legal
DESIGNDIR = design
BUILDDIR = build

SRCS = $(SRCDIR)/main.c $(SRCDIR)/infinity_matrix.c $(SRCDIR)/nsibidi_utils.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)
HEADERS = $(INCDIR)/infinity_matrix.h $(INCDIR)/nsibidi_utils.h

.PHONY: all build run legal design clean install uninstall

all: build

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

run: build
	@echo "----- [OBINexus Pi] Running Forensic Computation -----"
	@./$(TARGET)

legal: build
	@echo "----- [OBINexus Pi] Generating Legal Claim Framework -----"
	@./$(TARGET) --legal > $(LEGALDIR)/violation_manifest.txt
	@cat $(LEGALDIR)/CLAIM_TEMPLATE.md $(LEGALDIR)/violation_manifest.txt > $(LEGALDIR)/CLAIM_$(shell date +%Y%m%d).md
	@echo "[+] Legal claim generated: $(LEGALDIR)/CLAIM_$(shell date +%Y%m%d).md"

design: build
	@echo "----- [OBINexus Pi] Generating Nsibidi Design Seal -----"
	@./$(TARGET) --design > $(DESIGNDIR)/pi_seal.txt
	@echo "[+] Nsibidi design seal generated: $(DESIGNDIR)/pi_seal.txt"

clean:
	rm -rf $(BUILDDIR) $(TARGET) $(LEGALDIR)/violation_manifest.txt $(DESIGNDIR)/pi_seal.txt

install: build
	@cp $(TARGET) /usr/local/bin/
	@echo "[+] OBINexus π-Engine installed to /usr/local/bin/"

uninstall:
	@rm -f /usr/local/bin/$(TARGET)
	@echo "[+] OBINexus π-Engine uninstalled"
