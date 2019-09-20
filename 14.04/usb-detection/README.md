USB drive detection mechanism
=============================

USB detection mechanism make use of two signals: USR1 and USR2. Udev triggers
for these events are defined in 80-local.rules file.

Manual installation process is as follows:
```
copy 80-local.rules to /etc/udev/rules.d/
copy trigger1.sh and trigger2.sh /usr/local/bin/
udevadm control --reload
```

This can also be automatically done by running following script as root:
```
sudo setup_usb.sh
```
