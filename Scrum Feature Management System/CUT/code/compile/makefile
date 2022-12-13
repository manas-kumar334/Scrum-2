#####################################################################################################################################################
#   Created By: Manas Behera                                                                                                                        #
#   Created on: 11th December 2022                                                                                                                  #
#####################################################################################################################################################





SRCDIR=../src
INCLUDEDIR=../include
OBJDIR=../obj
BINDIR=../bin
CFLAGS= -c -g -Wall -I${INCLUDEDIR}


all:
	gcc ${CFLAGS} ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS} ${SRCDIR}/LogReg.c -o ${OBJDIR}/LogReg.o
	gcc ${CFLAGS} ${SRCDIR}/PMRMCRUD.c -o ${OBJDIR}/PMRMCRUD.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/LogReg.o ${OBJDIR}/PMRMCRUD.o -o ${BINDIR}/scrum.bin

clean:
	rm ${OBJDIR}/main.o ${OBJDIR}/LogReg.o ${OBJDIR}/PMRMCRUD.o -o ${BINDIR}/scrum.bin


##################################################### END OF MAKEFILE ############################################################################### 
