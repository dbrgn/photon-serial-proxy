all:
	rm -f *.bin && particle compile photon . && particle flash --usb *.bin
