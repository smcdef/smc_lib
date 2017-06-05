CROSS_COMPILE =

AS			= $(CROSS_COMPILE)as
LD			= $(CROSS_COMPILE)ld
CC			= $(CROSS_COMPILE)gcc
CPP			= $(CROSS_COMPILE)g++
AR			= $(CROSS_COMPILE)ar
NM			= $(CROSS_COMPILE)nm
STRIP		= $(CROSS_COMPILE)strip
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump

# export导出的变量是给子目录下的Makefile使用的
export AS LD CC CPP AR NM STRIP OBJCOPY OBJDUMP

# 编译器在编译时的参数设置
CFLAGS := 
# 添加头文件路径，不添加的话include目录下的头文件编译时找不到
CFLAGS += -I $(shell pwd)/smart_pointer
CFLAGS += -I $(shell pwd)/exception
CFLAGS += -I $(shell pwd)/object
CFLAGS += -I $(shell pwd)/list

# 链接器的链接参数设置
LDFLAGS := 

export CFLAGS LDFLAGS

TOPDIR := $(shell pwd)
export TOPDIR

# 定义将来编译生成的可执行程序的名字
TARGET := prj.out

# 添加项目中所有用到的源文件，有顶层目录下的.cpp文件，和子文件夹
# 添加顶层目录下的.cpp文件
obj-y += main.o

# 添加顶层目录下的子文件夹（注意目录名后面加一个/）
obj-y += exception/
obj-y += object/

all: 
	make -C ./ -f $(TOPDIR)/Makefile.build
	$(CPP) $(LDFLAGS) -o $(TARGET) built-in.o

clean:
	rm -f $(shell find -name "*.o")
	rm -f $(TARGET)

distclean:
	rm -f $(shell find -name "*.o")
	rm -f $(shell find -name "*.d")
	rm -f $(TARGET)
	