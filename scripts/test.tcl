tscope sim
 sched set beam1 on
 sched set beam2 on
 sched set beam3 off
 dx set length 25
 sched set dxtune range
 sched set multitarget on
 db set name sonatadb
 db set usedb on
 db set host localhost
 db set usedb on
 db set host localhost
 sched set target auto
 act set type target
 sched set beginfreq 2840
 sched set endfreq 3040
 sched set pipeline on
 act set targetbeam1 144
 act set targetbeam2 144
 act set targetprimary 144
 verbose level 2
