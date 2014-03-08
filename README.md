crontab parsing
===============

Parsing a crontab using the The Regents of the University of California implementation.


dependencies
===============

http://cron.sourcearchive.com/downloads/3.0pl1/cron_3.0pl1.orig.tar.gz


build
===============

gcc -o main main.c cron-3.0pl1.orig/entry.c cron-3.0pl1.orig/env.c cron-3.0pl1.orig/misc.c -I cron-3.0pl1.orig
