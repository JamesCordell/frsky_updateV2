This tool did not work last time I tried it and needs investigating.

# frsky_updateV2
Frsky_updateV2 tool used to update radio receivers and transmitters of the frsky range. Basically if you purchased a cheap receiver and it does not state which firmware is on it. This will either be Non_EU or EU. This tool is to be used with the fuc-3 usb lead. This process is not necessary if one has a Taranis Transmitter as this can facilitate the upgrade process.

The guide which shows pictures of the fuc-3 cable and the SCP cable. Note that the SPC cable is just a diode and DIY instrucations are in the guide.

This guide shows the PC method.
http://brchobbies.co.uk/catalog/images/brc_How%20to%20upgrade%20Smart%20Port%20enabled%20products.pdf

This guide shows both the Taranis method
http://www.frsky-rc.com/download/files/How%20To/How%20to%20upgrade%20Frsky%20smart%20port(s.port)%20products.pdf

The build instructions are.

apt-get install qt5-default


Unzip the source snapshot archive or clone the git repo

```bash
cd frsky_updateV2/linux
./compile.sh
cd build
./frsky_update_dft
```

