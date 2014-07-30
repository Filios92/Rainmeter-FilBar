; ================ Measures
[mHDD2]
Measure=FreeDiskSpace
Drive=C:
UpdateDivider=600
Substitute=" ":""

[mHDD1]
Measure=FreeDiskSpace
Drive=D:
UpdateDivider=600
Substitute=" ":""

; ================ Meters
[hdd-seg]
meter=image
meterstyle=separator
X=r

[hdd2FreeLabel]
meter=string
meterstyle=label
text=C:\

[hdd2FreeValue]
meter=string
measurename=mHDD2
meterstyle=value
autoscale=1
W=36

[hdd1FreeLabel]
meter=string
meterstyle=label
text=D:\
hidden=0

[hdd1FreeValue]
meter=string
measurename=mHDD1
meterstyle=value
autoscale=1
hidden=0
W=36

[endHddSeg]
meter=image
meterstyle=line
X=10R

