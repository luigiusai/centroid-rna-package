require 'mkmf'
CONFIG["CC"] = 'g++'
$CFLAGS += ' -Wall -DHAVE_CONFIG_H '
$LOCAL_LIBS += ' ../src/libcentroid.a ../src/contrafold/libcontrafold.a -lRNA -lboost_system-mt'
create_makefile("CentroidFold")
