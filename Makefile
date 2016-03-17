# Declaration of variables
CC_FLAGS 	= -w -std=c++11 -g -Wall -pedantic -Wextra
#CC_FLAGS	+= -fdiagnostics-color 

LL_FLAGS	= 

# ASAN=1 enables lib asan address sanitization
ASAN ?= 0

# DEBUG=1 enables debugging
DEBUG ?= 1
ifeq ($(DEBUG), 1)
$(info *** DEBUG BUILD)
ifeq ($(ASAN), 1)
CC_FLAGS	+= -fsanitize=address
#CC_FLAGS	+= -fsanitize=undefined # only for gcc 4.9+
LL_FLAGS	+= -fsanitize=address
#LL_FLAGS	+= -fsanitize=undefined # only for gcc 4.9+
endif
else 
$(info *** RELEASE BUILD)
CC_FLAGS	+= -O3
endif

# PROFILE=1 enables gprof
PROFILE ?= 0
ifeq ($(PROFILE), 1)
$(info PROFILING ENABLED)
CC_FLAGS 	+= -pg
LL_FLAGS 	+= -pg
endif

GOOGLE_TEST_DIR	= tests/google-test/

# Directories
INCLUDE_PATHS	= $(addprefix -I./, . common parser parser/exceptions tests standalone $(GOOGLE_TEST_DIR) $(GOOGLE_TEST_DIR)include/)

LIB_DIR		=
SRC_DIRS 	= parser common standalone

OBJ_DIR		= ./build
EXE_DIR		= ./build
DOC_DIR		= ./build
TEST_DIR	= ./tests
EXT_LIBS	= -pthread

MAINS		= $(GOOGLE_TEST_DIR)/src/gtest-all.cc standalone/main.cpp

# File names
EXEC 		= tsplibparser
CPP_SOURCES	= $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cpp))
SOURCES 	= $(filter-out $(MAINS), $(CPP_SOURCES))
CC_SOURCES	= $(GOOGLE_TEST_DIR)/src/gtest-all.cc
TEST_SOURCES	= $(wildcard $(TEST_DIR)/*.cpp) $(CC_SOURCES)
OBJECTS   	= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SOURCES)))) # only the objects common for the executables, in their respective original source directories

TEST_OBJECTS   	= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(TEST_SOURCES)))) # only the objects common for the executables, in their respective original source directories

all: $(EXE_DIR)/$(EXEC) $(EXE_DIR)/test

# Main target
$(EXE_DIR)/$(EXEC): $(OBJECTS) | $(EXE_DIR)
	$(CXX) ./standalone/main.cpp -o $@ $^ $(EXT_LIBS) $(LL_FLAGS) $(INCLUDE_PATHS) $(CC_FLAGS)

.phony tests:  $(EXE_DIR)/test | $(EXE_DIR)
	$(EXE_DIR)/test --gtest_color=yes

# Test target
$(EXE_DIR)/test: $(OBJECTS) $(TEST_OBJECTS) | $(EXE_DIR)
	$(CXX) $(GOOGLE_TEST_DIR)/src/gtest_main.cc -o $@ $^ $(INCLUDE_PATHS) $(CC_FLAGS) $(EXT_LIBS) 

# To obtain object files
$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@) # create the output folder for this object
	$(CXX) -c $(CC_FLAGS) $< -o $@ $(INCLUDE_PATHS)

$(OBJ_DIR)/%.o : %.cc | $(OBJ_DIR)
	@mkdir -p $(dir $@) # create the output folder for this object
	$(CXX) -c $(CC_FLAGS) $< -o $@ $(INCLUDE_PATHS)

$(EXE_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@
	
# To remove generated files
clean:
	rm -f $(EXE_DIR)/$(EXEC) $(EXE_DIR)/test
	rm -f $(OBJECTS) $(TEST_OBJECTS)
    
.PHONY:clean
