# Compilation information
CC_X86_64 = x86_64-w64-mingw32-gcc
CC_i686 = i686-w64-mingw32-gcc
FLAGS_i686 = -m32 -s -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable
FLAGS_x86_64 = -m64 -s -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable

# Necessary file information
SRC_FILE = main.c
BIN_NAME = a404ddemo.exe

# Default target
all: x86_64

# Compile for x86_64 architecture
x86_64:
	@${CC_X86_64} ${FLAGS_x86_64} ${SRC_FILE} -o ${BIN_NAME}
	@printf "[!] The backdoor has been compiled for the x86_64 architecture under the name ${BIN_NAME}\n"

# Compile for i686 architecture
i686:
	@${CC_i686} ${FLAGS_i686} ${SRC_FILE} -o ${BIN_NAME}
	@printf "[!] The backdoor has been compiled for the i686 architecture under the name ${BIN_NAME}\n"

# Clean target
clean:
	@printf "[x] The backdoor ${BIN_NAME} is going to be delete.\n"
	@rm -rf ${BIN_NAME}
