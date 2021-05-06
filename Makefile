UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
TARGET := bin/main
else
TARGET := bin\main.exe
endif

all: 
	gcc src/*.c -o ${TARGET} -I include

run:
ifeq (${UNAME}, Linux)
	konsole -e "bash -c ./$(TARGET)"
else
	CMD /c start $(TARGET)
endif