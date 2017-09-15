# ===============================================================
# Filename: Makefile
# -------------------------------
# Copyright(C),
# Author: zhenquan.qiu
# Version: V1.0.0
# Last modified: 31/08 2017 17:29
# Description:
#
# Change Log:
# NO.	Author		    Date		Modified
# 00	zhenquan.qiu	31/08 2017
# ===============================================================

ROOT := $(shell pwd)
OBJ_DIR ?= objs

Q := @
RM := $(Q)rm -rf

MAJOR_VERSION := 1
MINOR_VERSION := 0
BUG_VERSION := 0

TARGET := misc
TARGET_SO := lib$(TARGET).so.$(MAJOR_VERSION).$(MINOR_VERSION).$(BUG_VERSION)

# --------
# compiler
# --------
GCC_PATH := ~/Desktop/mips-gcc520-32bit/bin
GCC_NAME := mips-linux-gnu-

# CROSS_TOOL := $(GCC_PATH)/$(GCC_NAME)

CC := $(CROSS_TOOL)gcc

# ------
# cflags
# ------
CFLAGS := -Wall -I. -c -fPIC

MSG_CC := CC

# -------
# ldflags
# -------
SO_NAME := -Wl,-soname,lib$(TARGET).so.$(MAJOR_VERSION)

LDFLAGS := $(SO_NAME) -shared

MSG_LD := LD

# -------
# c files
# -------
SRC_C := $(wildcard *.c)
OBJ_C := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_C))
DEP_C := $(patsubst %.c, $(OBJ_DIR)/%.d, $(SRC_C))
DEPS  ?= $(DEP_C)
OBJS  ?= $(OBJ_C)

all: $(TARGET_SO)

$(TARGET_SO): $(OBJS)
	$(Q)echo $(MSG_LD) $<
	$(Q)$(CC) $(LDFLAGS) $(OBJS)  -o $(TARGET_SO)

	$(Q)ln -s $(TARGET_SO) lib$(TARGET).so
	$(Q)ln -s $(TARGET_SO) lib$(TARGET).so.$(MAJOR_VERSION)
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
	$(RM) $(OBJS)
	$(RM) $(DEPS)
	$(RM) $(TARGET)
	$(RM) lib$(TARGET).so
	$(RM) lib$(TARGET).so.$(MAJOR_VERSION)
	$(RM) $(TARGET_SO)

distclean: clean
	$(RM) $(OBJ_DIR)

debug:

.PHONY: all clean distclean debug

