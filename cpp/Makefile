PRG := challenge

SRC := main.cpp

OBJ := $(SRC:%.cpp=obj/%.o)

CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -std=c++17

V ?= 0

ifeq ($(V),0)
  QQ = @
  Q  = @
else
  ifeq ($(V),1)
    QQ = @
    Q  =
  else
    QQ =
    Q  =
  endif
endif

GEN_DEPS = -Wp,-M,-MP,-MT,obj/$(*F).o,-MF,obj/.deps/$(@F).d

all: $(PRG)

$(PRG): $(OBJ)
	-@echo "LD $@"
	$(Q)$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LIBS)

obj/%.o: %.cpp
	-@echo "CXX $@"
	-$(QQ)$(CXX) $(CXXFLAGS) -E $(GEN_DEPS) -o /dev/null $<
	$(Q)$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(PRG) obj

.PHONY: all clean

-include $(shell mkdir -p obj/.deps 2>/dev/null) $(wildcard obj/.deps/*)
