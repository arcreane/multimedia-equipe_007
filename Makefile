# DIRECTORIES
SDIR = src
IDIR = includes
ODIR = objects

# EXECUTABLE
EXE = main

# LIBRARIES
OPENCV_LIBS = -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_stitching

# DEPENDENCIES
DEPENDENCIES += $(wildcard $(IDIR)/*.hpp)

# SOURCES
SOURCES = $(wildcard $(SDIR)/*.cpp)

# OBJECTS
OBJECTS = $(SOURCES:$(SDIR)/%.cpp=$(ODIR)/%.o)

# FLAGS
CPPFLAGS = -Wall -I$(IDIR)
LDFLAGS = $(OPENCV_LIBS)

# MAKE RULES

# Generate an object from cpp file
$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPENDENCIES)
	g++ $(CPPFLAGS) -c -o $@ $<

# Generate executable from objects
$(EXE): $(OBJECTS)
	g++ -o $@ $^ $(LDFLAGS)

# Clean command
clean:
	rm -rf $(ODIR) $(EXE)

# Install command
install:
	mkdir -p $(ODIR)

# Do everything :)
all: clean install $(EXE)