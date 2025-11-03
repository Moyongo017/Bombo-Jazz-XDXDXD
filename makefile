bin\programa : src\main.cpp include\Foco.hpp
	c++ src/main.cpp -o bin/programa -I include

run : bin/animacion
	./bin/animacion

bin/animacion : src/animacion.cpp include/*.hpp
	@mkdir -p bin
	g++ -Iinclude -o bin/animacion src/animacion.cpp -lftxui-component -lftxui-dom -lftxui-screen