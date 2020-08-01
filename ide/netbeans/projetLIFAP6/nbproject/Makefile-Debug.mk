#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/52a4beb5/AIScrabble.o \
	${OBJECTDIR}/_ext/52a4beb5/Gaddag.o \
	${OBJECTDIR}/_ext/52a4beb5/GaddagNode.o \
	${OBJECTDIR}/_ext/52a4beb5/KicksInformation.o \
	${OBJECTDIR}/_ext/52a4beb5/LetterBag.o \
	${OBJECTDIR}/_ext/52a4beb5/LetterOfPlayer.o \
	${OBJECTDIR}/_ext/52a4beb5/LetterPointTable.o \
	${OBJECTDIR}/_ext/52a4beb5/Player.o \
	${OBJECTDIR}/_ext/52a4beb5/board.o \
	${OBJECTDIR}/_ext/52a4beb5/bonus.o \
	${OBJECTDIR}/_ext/52a4beb5/main.o \
	${OBJECTDIR}/_ext/52a4beb5/spot.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../../../bin/projet_lifap6

../../../bin/projet_lifap6: ${OBJECTFILES}
	${MKDIR} -p ../../../bin
	${LINK.cc} -o ../../../bin/projet_lifap6 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/52a4beb5/AIScrabble.o: ../../../src/AIScrabble.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/AIScrabble.o ../../../src/AIScrabble.cpp

${OBJECTDIR}/_ext/52a4beb5/Gaddag.o: ../../../src/Gaddag.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/Gaddag.o ../../../src/Gaddag.cpp

${OBJECTDIR}/_ext/52a4beb5/GaddagNode.o: ../../../src/GaddagNode.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/GaddagNode.o ../../../src/GaddagNode.cpp

${OBJECTDIR}/_ext/52a4beb5/KicksInformation.o: ../../../src/KicksInformation.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/KicksInformation.o ../../../src/KicksInformation.cpp

${OBJECTDIR}/_ext/52a4beb5/LetterBag.o: ../../../src/LetterBag.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/LetterBag.o ../../../src/LetterBag.cpp

${OBJECTDIR}/_ext/52a4beb5/LetterOfPlayer.o: ../../../src/LetterOfPlayer.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/LetterOfPlayer.o ../../../src/LetterOfPlayer.cpp

${OBJECTDIR}/_ext/52a4beb5/LetterPointTable.o: ../../../src/LetterPointTable.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/LetterPointTable.o ../../../src/LetterPointTable.cpp

${OBJECTDIR}/_ext/52a4beb5/Player.o: ../../../src/Player.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/Player.o ../../../src/Player.cpp

${OBJECTDIR}/_ext/52a4beb5/board.o: ../../../src/board.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/board.o ../../../src/board.cpp

${OBJECTDIR}/_ext/52a4beb5/bonus.o: ../../../src/bonus.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/bonus.o ../../../src/bonus.cpp

${OBJECTDIR}/_ext/52a4beb5/main.o: ../../../src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/main.o ../../../src/main.cpp

${OBJECTDIR}/_ext/52a4beb5/spot.o: ../../../src/spot.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/52a4beb5
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/52a4beb5/spot.o ../../../src/spot.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
