# ===============================================================
# Filename: Makefile
# -------------------------------
# Copyright(C),
# Author: zhenquan.qiu
# Version: V1.0.0
# Last modified: 31/08 2017 17:44
# Description:
#
# Change Log:
# NO.	Author		    Date		Modified
# 00	zhenquan.qiu	31/08 2017
# ===============================================================

ROOT    := $(shell pwd)
OBJ_DIR ?= objs

TARGET := demo

Q := @
RM := $(Q)rm -rf

GCC_PATH := ~/Desktop/mips-gcc520-32bit/bin
GCC_NAME := mips-linux-gnu-

# CROSS_TOOL := $(GCC_PATH)/$(GCC_NAME)

CC := $(CROSS_TOOL)gcc

# cflags
CFLAGS := -Wall -g
CFLAGS += -c
CFLAGS += -I.

MSG_CC := CC

# ldflags
LDFLAGS :=

MSG_LD := LD

# c files
SRC_C := $(wildcard *.c)
OBJ_C := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_C))
DEP_C := $(patsubst %.c, $(OBJ_DIR)/%.d, $(SRC_C))
DEPS  ?= $(DEP_C)
OBJS  ?= $(OBJ_C)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(Q)@echo $(MSG_LD) $^
	$(Q)$(CC) $(LDFLAGS) $^ -o $@

#
# make *.c
#
$(OBJ_C): $(OBJ_DIR)/%.o : %.c
	$(Q)mkdir -p $(dir $@)
	$(Q)echo $(MSG_CC) $<
	$(Q)$(CC) -c $(CFLAGS) $< -o $@

$(DEP_C): $(OBJ_DIR)/%.d : %.c
	$(Q)mkdir -p $(dir $@);
	$(Q)$(CC) -MM $(CFLAGS) -MT $(@:%.d=%.o) $< >$@

sinclude $(DEPS)

clean:
	$(RM) $(OBJ_C)
	$(RM) $(DEP_C)
	$(RM) $(TARGET)

distclean: clean
	$(RM) $(OBJ_DIR)

debug:
	$(Q)echo $(SRC_C)
	$(Q)echo $(OBJ_C)
	$(Q)echo $(DEP_C)
	$(Q)echo $(OBJS)

.PHONY: all clean distclean debug





