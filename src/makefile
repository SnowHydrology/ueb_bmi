CXX = g++
MPICXX = mpicxx 
CUDAXX = nvcc 
CUDAFLAGS = -x cu -arch=sm_20 -dc -lineinfo
CUDALFLAGS = -arch=sm_20 
CXXFLAGS = -std=c++0x -g -Wall 
#--compiler-options -Wall
LINKFLAGS = -std=c++0x -g
LIBDIRS = -L/usr/local/lib
LDFLAGS = -lnetcdf -lhdf5_hl -lhdf5 -lcurl -lm -lz -ldl 
#LDFLAGS = -lpnetcdf -lnetcdf -lhdf5_hl -lhdf5 -lm -lz -ldl -lmpi -lmpicxx
INCDIRS = -I/usr/local/include
TARGET = uebpar
CXX_SRCS = main.cpp canopy.cpp matrixnvector.cpp ncfunctions.cpp snowdgtv.cpp snowdv.cpp snowxv.cpp uebdecls.cpp uebinputs.cpp bmi_ueb.cxx
CXX_SRCS_del =      canopy.cpp matrixnvector.cpp ncfunctions.cpp snowdgtv.cpp snowdv.cpp snowxv.cpp uebdecls.cpp uebinputs.cpp
#CXX_SRCS = main.cpp ../extern/UEB/canopy.cpp ../extern/UEB/matrixnvector.cpp ../extern/UEB/ncfunctions.cpp ../extern/UEB/snowdgtv.cpp ../extern/UEB/snowdv.cpp ../extern/UEB/snowxv.cpp ../extern/UEB/uebdecls.cpp ../extern/UEB/uebinputs.cpp
OBJS = $(CXX_SRCS:.cpp=.o)
OBJS_del = $(CXX_SRCS_del:.cpp=.o)

$(TARGET) : $(OBJS)
	$(MPICXX) $(LINKFLAGS) -o $@ $^ $(LIBDIRS) $(LDFLAGS)
#$(CUDAXX) $(CUDALFLAGS) $(LINKFLAGS) -o $@ $^ $(LIBDIRS) $(LDFLAGS)

%.o : %.cpp
	$(MPICXX) $(CXXFLAGS) $(INCDIRS) -c $<

clean :
	$(RM) $(OBJS_del) $(TARGET)
