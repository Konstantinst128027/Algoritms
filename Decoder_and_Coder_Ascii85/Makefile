CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall
CXX_FLAG = -Iinclude
GTEST_LIBS = -lgtest -lgtest_main -lpthread

PAPKA = src
PROJ_FILES = $(wildcard $(PAPKA)/*.cpp)
OBJ_FILES = $(PROJ_FILES:.cpp=.o)

TEST_PAPKA = tests
TEST_FILES = $(wildcard $(TEST_PAPKA)/*.cpp)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)

FUNCTION_PAPKA = function
FUNCTION_FILES = $(wildcard $(FUNCTION_PAPKA)/*.cpp)
FUNCTION_OBJ_FILES = $(FUNCTION_FILES:.cpp=.o)

EXECUTABLE_1 = main
EXECUTABLE_2 = tests
$(EXECUTABLE_1): $(OBJ_FILES) $(FUNCTION_OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(CXX_FLAG) $(OBJ_FILES) $(FUNCTION_OBJ_FILES) -o $(EXECUTABLE_1)
$(EXECUTABLE_2): $(TEST_OBJ_FILES) $(FUNCTION_OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(CXX_FLAG) $(TEST_OBJ_FILES) $(GTEST_LIBS) $(FUNCTION_OBJ_FILES) -o $(EXECUTABLE_2)
$(PAPKA)/%.o: $(PAPKA)/%.cpp
	$(CXX) $(CXXFLAGS) $(CXX_FLAG) -c $< -o $@
	
$(TEST_PAPKA)/%.o: $(TEST_PAPKA)/%.cpp
	$(CXX) $(CXXFLAGS) $(CXX_FLAG) -c $< -o $@	

$(FUNCTION_PAPKA)/%.o: $(FUNCTION_PAPKA)/%.cpp
	$(CXX) $(CXXFLAGS) $(CXX_FLAG) -c $< -o $@
clean:
	rm -f $(TEST_PAPKA)/*.o $(PAPKA)/*.o $(FUNCTION_PAPKA)/*.o
cleanall:
	rm -f $(TEST_PAPKA)/*.o $(PAPKA)/*.o $(FUNCTION_PAPKA)/*.o $(EXECUTABLE_1) $(EXECUTABLE_2)
