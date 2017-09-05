# ===============================================================
# Filename: Makefile
# -------------------------------
# Copyright(C),
# Author: zhenquan.qiu
# Version: V1.0.0
# Last modified: 05/09 2017 14:23
# Description:
# 
# Change Log:
# NO.	Author		    Date		Modified
# 00	zhenquan.qiu	05/09 2017
# ===============================================================

ROOT := $(shell pwd)
TARGET := array

RM := $(Q)rm -rf

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
	gcc $(CFLAGS) $(C_SRC)
	gcc $(LDFLAGS) $(O_SRC) -o $(TARGET)

clean:
	$(RM) $(O_SRC)
	$(RM) $(TARGET)

debug:
	echo $(C_SRC)
	echo $(O_SRC)

