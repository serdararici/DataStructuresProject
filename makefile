hepsi: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/Test.cpp -o ./lib/Test.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/DogruKuyrugu.cpp -o ./lib/DogruKuyrugu.o
	g++ -c -I "./include" ./src/DosyaOku.cpp -o ./lib/DosyaOku.o
	g++ -c -I "./include" ./src/DugumAVL.cpp -o ./lib/DugumAVL.o
	g++ -c -I "./include" ./src/AVL.cpp -o ./lib/AVL.o
bagla:
	g++ ./lib/DugumAVL.o ./lib/AVL.o ./lib/DosyaOku.o ./lib/DogruKuyrugu.o ./lib/Dugum.o ./lib/Test.o -o ./bin/program
calistir:
	./bin/program