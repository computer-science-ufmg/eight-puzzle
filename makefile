CC=g++
STD=c++17
CFLAGS=-Wall -Wextra -std=$(STD)

TARGET_NAME=./TP1
BUILD_PATH=./build
SOURCE_PATH=./src
LIB_PATH=./include
# INPUT_PATH=./input
# OUTPUT_PATH=./output

SOURCE_EXT := cpp
SOURCES := $(shell find $(SOURCE_PATH) -path '*.$(SOURCE_EXT)')
OBJECTS := $(patsubst $(SOURCE_PATH)/%,$(BUILD_PATH)/%,$(SOURCES:.$(SOURCE_EXT)=.o))

all: $(TARGET_NAME)

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(LIB_PATH)/%.hpp
	dirname $@ | xargs mkdir -p
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET_NAME): $(OBJECTS) ./main.cpp
	$(CC) $(CFLAGS) -o $(TARGET_NAME) ./main.cpp $(OBJECTS)

clean:
	rm -rf $(BUILD_PATH)/*
	rm $(TARGET_NAME)

run: $(TARGET_NAME)
	$(TARGET_NAME)

mem: $(TARGET_NAME)
	valgrind --leak-check=full --show-leak-kinds=all $(TARGET_NAME)

test: $(TARGET_NAME)
	@bash ./run-test $(TARGET_NAME) $(ALG) $(LIMIT)

time: $(TARGET_NAME)
	@bash ./measure-time $(TARGET_NAME) > outputs/time.csv
