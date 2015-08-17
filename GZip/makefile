INC = include
SRC = src
OBJ = obj
BIN = bin
LIB = lib
CXX= g++
CPPFLAGS= -Wall -g -c

all: test_1_tablas test_2_lz test_3_huffman test_4_flujo test_5_flujos mp2gzip

documentación:
	doxygen doc/doxys/Doxyfile

$(OBJ)/crc32.o: $(SRC)/crc32.cpp $(INC)/crc32.h
	$(CXX) $(CPPFLAGS) $(SRC)/crc32.cpp -I $(INC)/ -o $(OBJ)/crc32.o

$(OBJ)/vd.o: $(SRC)/vd.cpp $(INC)/vd.h
	$(CXX) $(CPPFLAGS) $(SRC)/vd.cpp -I $(INC)/ -o $(OBJ)/vd.o

$(OBJ)/lz.o: $(SRC)/lz.cpp $(INC)/vd.h $(INC)/crc32.h $(INC)/lz.h 
	$(CXX) $(CPPFLAGS) $(SRC)/lz.cpp -I $(INC)/ -o $(OBJ)/lz.o

$(OBJ)/vector_bits.o: $(SRC)/vector_bits.cpp $(INC)/vector_bits.h
	$(CXX) $(CPPFLAGS) $(SRC)/vector_bits.cpp -I $(INC)/ -o $(OBJ)/vector_bits.o

$(OBJ)/tabla_LADD_DAA.o: $(SRC)/tabla_LADD_DAA.cpp $(INC)/tabla_LADD_DAA.h $(INC)/vector_bits.h
	$(CXX) $(CPPFLAGS) $(SRC)/tabla_LADD_DAA.cpp -I $(INC)/ -o $(OBJ)/tabla_LADD_DAA.o

$(OBJ)/tabla_huffman.o: $(SRC)/tabla_huffman.cpp $(INC)/tabla_huffman.h $(INC)/vector_bits.h
	$(CXX) $(CPPFLAGS) $(SRC)/tabla_huffman.cpp -I $(INC)/ -o $(OBJ)/tabla_huffman.o

$(OBJ)/test_1_tablas.o: $(SRC)/test_1_tablas.cpp $(INC)/tabla_LADD_DAA.h $(INC)/tabla_huffman.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_1_tablas.cpp -I $(INC)/ -o $(OBJ)/test_1_tablas.o

$(OBJ)/test_2_lz.o: $(SRC)/test_2_lz.cpp $(INC)/tabla_LADD_DAA.h $(INC)/tabla_huffman.h $(INC)/crc32.h $(INC)/lz.h  $(INC)/vd.h $(INC)/vector_bits.h 
	$(CXX) $(CPPFLAGS) $(SRC)/test_2_lz.cpp -I $(INC)/ -o $(OBJ)/test_2_lz.o

$(OBJ)/test_3_huffman.o: $(SRC)/test_3_huffman.cpp $(INC)/tabla_LADD_DAA.h $(INC)/tabla_huffman.h $(INC)/lz.h $(INC)/vd.h $(INC)/vector_bits.h $(INC)/crc32.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_3_huffman.cpp -I $(INC)/ -o $(OBJ)/test_3_huffman.o
	
$(OBJ)/test_4_flujo.o: $(SRC)/test_4_flujo.cpp  $(INC)/tabla_LADD_DAA.h $(INC)/tabla_huffman.h $(INC)/lz.h $(INC)/vd.h $(INC)/vector_bits.h $(INC)/crc32.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_4_flujo.cpp -I $(INC)/ -o $(OBJ)/test_4_flujo.o
	
$(OBJ)/test_5_flujos.o: $(SRC)/test_5_flujos.cpp  $(INC)/tabla_LADD_DAA.h $(INC)/tabla_huffman.h $(INC)/lz.h $(INC)/vd.h $(INC)/vector_bits.h $(INC)/crc32.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_5_flujos.cpp -I $(INC)/ -o $(OBJ)/test_5_flujos.o

$(OBJ)/gzip.o: $(SRC)/gzip.cpp $(INC)/tabla_LADD_DAA.h $(INC)/tabla_huffman.h $(INC)/crc32.h $(INC)/lz.h $(INC)/vd.h
	$(CXX) $(CPPFLAGS) $(SRC)/gzip.cpp -I $(INC)/ -o $(OBJ)/gzip.o

test_1_tablas: $(BIN)/test_1_tablas

$(BIN)/test_1_tablas:  $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/test_1_tablas.o
	$(CXX) -o $(BIN)/test_1_tablas $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/test_1_tablas.o

test_2_lz: $(BIN)/test_2_lz
	
$(BIN)/test_2_lz: $(OBJ)/vd.o $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/crc32.o $(OBJ)/lz.o $(OBJ)/test_2_lz.o
	$(CXX) -o $(BIN)/test_2_lz $(OBJ)/vd.o $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/crc32.o $(OBJ)/lz.o $(OBJ)/test_2_lz.o

test_3_huffman:$(BIN)/test_3_huffman
$(BIN)/test_3_huffman: $(OBJ)/vd.o $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/crc32.o $(OBJ)/lz.o $(OBJ)/test_3_huffman.o
	$(CXX) -o $(BIN)/test_3_huffman $(OBJ)/vd.o $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/crc32.o $(OBJ)/lz.o $(OBJ)/test_3_huffman.o

test_4_flujo: $(BIN)/test_4_flujo
$(BIN)/test_4_flujo: $(OBJ)/vd.o $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/crc32.o $(OBJ)/lz.o $(OBJ)/test_4_flujo.o
	$(CXX) -o $(BIN)/test_4_flujo $(OBJ)/vd.o $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/crc32.o $(OBJ)/lz.o $(OBJ)/test_4_flujo.o

test_5_flujos: $(BIN)/test_5_flujos
$(BIN)/test_5_flujos: $(OBJ)/vd.o $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/crc32.o $(OBJ)/lz.o $(OBJ)/test_5_flujos.o
	$(CXX) -o $(BIN)/test_5_flujos $(OBJ)/vd.o $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/crc32.o $(OBJ)/lz.o $(OBJ)/test_5_flujos.o

mp2gzip: $(BIN)/mp2gzip
$(BIN)/mp2gzip: $(OBJ)/vd.o $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/crc32.o $(OBJ)/lz.o $(OBJ)/gzip.o
	$(CXX) -o $(BIN)/mp2gzip $(OBJ)/vd.o $(OBJ)/vector_bits.o $(OBJ)/tabla_huffman.o $(OBJ)/tabla_LADD_DAA.o $(OBJ)/crc32.o $(OBJ)/lz.o $(OBJ)/gzip.o

clean:
	@echo "Mr proper ya no se llama Mr proper. Ahora se llama don limpio... Liampiando..."
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ validaciones/*~ ./*~ $(LIB)/lib*.a

mrproper: clean 
	-rm $(BIN)/* doc/html/* doc/latex/* doc/rtf/*
	@echo "Don limpio a hecho su función. Ha dejado todo como una patena"