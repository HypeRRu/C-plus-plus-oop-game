BUILD_DIR = ./build
INTERFACE_PATH = ./interfaces
CELLS_PATH = ./cells
BUILD_PATH = ./build
UTILS_PATH = ./utils
GRAPHICS_PATH = ./graphics
FILES = main.cpp field.cpp $(CELLS_PATH)/cell.cpp
TARGETS = $(BUILD_DIR)/main.o $(BUILD_DIR)/field.o $(BUILD_DIR)/cell.o \
	$(BUILD_DIR)/end_cell.o $(BUILD_DIR)/start_cell.o $(BUILD_DIR)/game.o \
	$(BUILD_DIR)/field_generator.o $(BUILD_DIR)/renderer.o \
	$(BUILD_DIR)/texture_manager.o $(BUILD_DIR)/cells_iterator.o
HEADERS = field.h $(CELLS_PATH)/cell.h $(CELLS_PATH)/end_cell.h \
	$(CELLS_PATH)/start_cell.h $(INTERFACE_PATH)/item.h game.h \
	$(UTILS_PATH)/field_generator.h $(UTILS_PATH)/cells_iterator.h \
	$(INTERFACE_PATH)/iterator.h
GRAPHICS_HEADERS = $(GRAPHICS_PATH)/texture_manager.h \
	$(GRAPHICS_PATH)/renderer.h
COMP = g++ -std=c++2a
SFML_LINK = -lsfml-graphics -lsfml-window -lsfml-system

all: compile
	
compile: $(TARGETS)
	$(COMP) $(TARGETS) -o main $(SFML_LINK)

$(BUILD_DIR)/main.o: main.cpp $(HEADERS)
	$(COMP) main.cpp -c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/field.o: field.cpp $(HEADERS)
	$(COMP) field.cpp -c -o $(BUILD_DIR)/field.o

$(BUILD_DIR)/cell.o: $(CELLS_PATH)/cell.cpp $(CELLS_PATH)/cell.h $(INTERFACE_PATH)/item.h
	$(COMP) $(CELLS_PATH)/cell.cpp -c -o $(BUILD_DIR)/cell.o

$(BUILD_DIR)/end_cell.o: $(CELLS_PATH)/end_cell.cpp $(CELLS_PATH)/cell.h $(INTERFACE_PATH)/item.h $(CELLS_PATH)/end_cell.h
	$(COMP) $(CELLS_PATH)/end_cell.cpp -c -o $(BUILD_DIR)/end_cell.o

$(BUILD_DIR)/start_cell.o: $(CELLS_PATH)/start_cell.cpp $(CELLS_PATH)/cell.h $(INTERFACE_PATH)/item.h $(CELLS_PATH)/start_cell.h
	$(COMP) $(CELLS_PATH)/start_cell.cpp -c -o $(BUILD_DIR)/start_cell.o

$(BUILD_DIR)/game.o: game.cpp $(HEADERS) $(GRAPHICS_HEADERS)
	$(COMP) game.cpp -c -o $(BUILD_DIR)/game.o

$(BUILD_DIR)/field_generator.o: $(UTILS_PATH)/field_generator.cpp $(HEADERS)
	$(COMP) $(UTILS_PATH)/field_generator.cpp -c -o $(BUILD_DIR)/field_generator.o

$(BUILD_DIR)/renderer.o: $(GRAPHICS_PATH)/renderer.cpp $(GRAPHICS_HEADERS)
	$(COMP) $(GRAPHICS_PATH)/renderer.cpp -c -o $(BUILD_DIR)/renderer.o

$(BUILD_DIR)/texture_manager.o: $(GRAPHICS_PATH)/texture_manager.cpp $(GRAPHICS_PATH)/texture_manager.h
	$(COMP) $(GRAPHICS_PATH)/texture_manager.cpp -c -o $(BUILD_DIR)/texture_manager.o

$(BUILD_DIR)/cells_iterator.o: $(UTILS_PATH)/cells_iterator.cpp \
	$(UTILS_PATH)/cells_iterator.h \
	$(CELLS_PATH)/cell.h $(INTERFACE_PATH)/iterator.h field.h
	$(COMP) $(UTILS_PATH)/cells_iterator.cpp -c -o $(BUILD_DIR)/cells_iterator.o

clean: ./main
	rm $(BUILD_DIR)/*
	rm ./main 
