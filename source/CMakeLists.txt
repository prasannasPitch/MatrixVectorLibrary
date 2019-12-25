project(testVectorMatrix)

message("Configuring project testVectorMatrix")

#list of source files
set(SOURCES
	./testVectorMatrix.cpp
	./Matrix.cpp
	./Vector.cpp
)


#list of header files
set(HEADERS
	./Arithmetic.hpp
	./Matrix.hpp
	./Vector.hpp
)

#create executable from sources
add_executable(testVectorMatrix ${SOURCES} ${HEADERS})
#target_link_libraries(testVectorMatrix)
