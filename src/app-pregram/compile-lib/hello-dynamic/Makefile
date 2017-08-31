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
TARGET := hello

RM := $(Q)rm -rf

CFLAGS := -fPIC
CFLAGS += -Wall
CFLAGS += -c
CFLAGS += -I.

LDFLAGS := -shared

# c files
C_SRC := $(wildcard *.c)
O_SRC := $(patsubst %.c, %.o, $(C_SRC))

all:
	gcc $(CFLAGS) $(C_SRC)
	gcc $(LDFLAGS) $(O_SRC) -o lib$(TARGET).so

clean:
	$(RM) $(O_SRC)
	$(RM) lib$(TARGET).so

debug:
	echo $(C_SRC)
	echo $(O_SRC)

