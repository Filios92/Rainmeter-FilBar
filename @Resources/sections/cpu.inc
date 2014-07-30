
; ================ Measures
[mCPU]
Plugin=Plugins\PowerPlugin.dll
Measure=CPU
PowerState=MHZ
Substitute=" ":""

[mRAM]
Measure=PhysicalMemory
UpdateDivider=10
IfBelowValue=1073741824
IfBelowAction=!SetOption "RamValue" "NumOfDecimals" 0
IfAboveValue=1073741823
IfAboveAction=!SetOption "RamValue" "NumOfDecimals" 1

[MeasureTopProcessUsage]
Measure=Plugin
Plugin=AdvancedCPU
TopProcess=1
CPUExclude=Idle

[MeasureTopProcessName]
Measure=Plugin
Plugin=AdvancedCPU
TopProcess=2
CPUExclude=Idle

; ================ Meters
[cpu-seg]
meter=image
meterstyle=separator
X=r

[cpuLabel]
meter=string
meterstyle=label
text=cpu
W=26

[CpuValue]
Meter=String
MeasureName=mCPU
MeterStyle=value
Text=%1%
W=36
group=c.norm

[ramLabel]
meter=string
meterstyle=label
text=ram
X=40r
W=30
group=c.norm

[RamValue]
Meter=String
MeasureName=mRAM
MeterStyle=value
Text="%1"
Autoscale=1
NumOfDecimals=1
W=36
group=c.norm

[TopProcessName]
Meter=STRING
MeasureName=MeasureTopProcessName
MeterStyle=value
X=([cpuvalue:X])
clipstring=2
clipstringW=([cpuvalue:W]+[ramlabel:W]+[ramvalue:W])
Hidden=1
group=c.hov

[cpuHover]
meter=image
solidcolor=0,0,0,1
X=[cpulabel:X]
Y=[bg:Y]
W=([cpulabel:W]+[cpuvalue:W]+[ramlabel:W]+[ramvalue:W])
H=[bg:H]
MouseOverAction=!Execute [!ShowMeterGroup c.hov][!HideMeterGroup c.norm][!Redraw]
MouseLeaveAction=!Execute [!HideMeterGroup c.hov][!ShowMeterGroup c.norm][!Redraw]
LeftMouseUpAction=!Execute ["taskmgr"]

[end-cpu-seg]
meter=image
meterstyle=line
X=10R

