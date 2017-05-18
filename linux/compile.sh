#!/bin/sh
set -e
qmake-qt4 -makefile
mv Makefile Makefile.build
#force 32bit architecture
sed -i -e 's|-m64|-m32|g' -e 's|lib64|lib|g' -e 's|^\(LINK[[:space:]]*=.*\)$|\1 -m32|' Makefile.build
make -f Makefile.build clean all
if [ $? = 0 ]; then
  rm -rf libs 2>/dev/null
  mkdir libs
  for l in $(ldd frsky_update_dft | sed -n -e 's|^.* => \(/[^ ]*\) .*$|\1|p')
  do
    cp $l libs/
  done
  mv frsky_update_dft libs/
  printf "#!/bin/sh\nexport LD_LIBRARY_PATH=./libs\nexec ./libs/frsky_update_dft\n" >frsky_update_dft
  chmod +x ./frsky_update_dft
  tar cvjf frsky_updateV2_linux.tar.bz2 ./frsky_update_dft ./libs
fi
