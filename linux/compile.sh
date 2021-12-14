#!/bin/sh
set -e
rm -rf build 2>/dev/null
mkdir build
cd build
qmake ../../frsky_updateV2.pro
#force 32bit architecture  ... why?
#sed -i -e 's|-m64|-m32|g' -e 's|lib64|lib|g' -e 's|^\(LINK[[:space:]]*=.*\)$|\1 -m32|' Makefile.build
make -j4 all
if [ $? = 0 ]; then
  mkdir libs
  for l in $(ldd frsky_update_dft | sed -n -e 's|^.* => \(/[^ ]*\) .*$|\1|p')
  do
    cp $l libs/
  done
  mv frsky_update_dft libs/
  printf '#!/bin/sh\nexport LD_LIBRARY_PATH=$(dirname $0)/libs\nexec $(dirname $0)/libs/frsky_update_dft\n' >frsky_update_dft
  chmod +x ./frsky_update_dft
  tar cvjf frsky_updateV2_linux.tar.bz2 ./frsky_update_dft ./libs
fi
make clean
