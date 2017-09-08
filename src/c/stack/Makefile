# ===============================================================
# Filename: Makefile
# -------------------------------
# Copyright(C),
# Author: zhenquan.qiu
# Version: V1.0.0
# Last modified: 07/09 2017 09:18
# Description:
# 
# Change Log:
# NO.	Author		    Date		Modified
# 00	zhenquan.qiu	07/09 2017
# ===============================================================

ROOT := $(shell pwd)
TARGET := stack-direction

RM := $(Q)rm -rf

GCC_PATH := ~/Desktop/mips-gcc520-32bit/bin
GCC_NAME := mips-linux-gnu-

# CROSS_TOOL := $(GCC_PATH)/$(GCC_NAME)

CC := $(CROSS_TOOL)gcc

# cflags
CFLAGS := -Wall -g
CFLAGS += -c
CFLAGS += -I.

# ldflags
LDFLAGS :=

# c files
C_SRC := $(wildcard *.c)
O_SRC := $(patsubst %.c, %.o, $(C_SRC))

all:
	$(CC) $(CFLAGS) $(C_SRC)
	$(CC) $(LDFLAGS) $(O_SRC) -o $(TARGET)

clean:
	$(RM) $(O_SRC)
	$(RM) $(TARGET)

debug:
	echo $(C_SRC)
	echo $(O_SRC)

