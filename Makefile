CXX = g++
CXXFLAGS = -std=c++17
LDLIBS = -lncurses

SRC_DIR = src
BUILD_DIR = $(SRC_DIR)/build
DOC_DIR = doc
OUTPUT_DIR = .

TARGET = $(OUTPUT_DIR)/filipleo
DOC_TARGET = index.html

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

TEST_DIR = src/tests
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/test_%.o, $(TEST_SOURCES)) $(BUILD_DIR)/Soldier.o $(BUILD_DIR)/Cell.o $(BUILD_DIR)/Tower.o

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

$(DOC_DIR)/$(DOC_TARGET):
	doxygen Doxyfile

.PHONY: all compile run debug doc clean test

all: $(TARGET) run

compile: $(TARGET)

run: $(TARGET)
	cd $(OUTPUT_DIR) && ./filipleo

debug: $(TARGET)
	valgrind --leak-check=full --track-origins=yes $(TARGET)

doc: $(DOC_DIR)/$(DOC_TARGET)

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET) $(OUTPUT_DIR)/test
	rm -rf $(DOC_DIR)
	rm -rf $(BUILD_DIR)

test: $(TARGET) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT_DIR)/test $(TEST_OBJECTS) $(LDLIBS)
	cd $(OUTPUT_DIR) && ./test
