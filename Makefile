# Macros
RM = /bin/rm -f  # Para limpiar
CC = g++         # Para compilar
#---------------------------------------------------------
# Opciones de compilación
CPPFLAGS = -std=c++11 # Opciones compilación
#---------------------------------------------------------
# Vars
RATIONAL = Rational
MAIN = Calculadora
#---------------------------------------------------------
${MAIN}:  ${MAIN}.o ${RATIONAL}.o
	$(CC) ${MAIN}.o ${RATIONAL}.o -o ${MAIN} $(CPPFLAGS)
#---------------------------------------------------------
${MAIN}.o: ${MAIN}.cpp
	$(CC)  ${MAIN}.cpp -c $(CPPFLAGS)
#---------------------------------------------------------
${RATIONAL}.o: ${RATIONAL}.cpp ${RATIONAL}.hpp
	$(CC) 	   ${RATIONAL}.cpp -c $(CPPFLAGS)
#---------------------------------------------------------
clean:
	$(RM) ${MAIN} ${MAIN}.o
	$(RM) ${RATIONAL} ${RATIONAL}.o