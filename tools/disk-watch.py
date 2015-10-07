#!/usr/bin/env python

# codigo muy malo, necessito escribir otra vez

import sys
import os
import time

if len(sys.argv)!=2:
	print 'para utilizar: %s <diskname>' % (sys.argv[0])
	exit()

diskname = sys.argv[1]

while 1:
	os.system('df -h  | grep '+diskname + " | awk '{print $5}' >/tmp/disk-percent")
	finline = open('/tmp/disk-percent','r').read()
	pc = int(finline.split('%')[0])
	print 'disk percent: %d' % (pc)
	if (pc>90):
		os.system('killall -9 rage')
		print 'killed rage.... at %d %%' % (pc)
		exit()
	time.sleep(10)
	
