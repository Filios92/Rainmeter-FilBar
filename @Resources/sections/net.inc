; ================ Measures
[mNetIn]
Measure=NetIn
IfBelowValue=1048576
IfBelowAction=!SetOption "netInValue" "NumOfDecimals" 0
IfAboveValue=1048575
IfAboveAction=!SetOption "netInValue" "NumOfDecimals" 1

[mNetOut]
Measure=NetOut
IfBelowValue=1048576
IfBelowAction=!SetOption "netOutValue" "NumOfDecimals" 0
IfAboveValue=1048575
IfAboveAction=!SetOption "netOutValue" "NumOfDecimals" 1

[mNetInTotal]
Measure=NetIn
Cumulative=1

[mNetOutTotal]
Measure=NetOut
Cumulative=1

; ================ Meters
[net-seg]
meter=image
meterstyle=separator
X=r

[netInLabel]
meter=string
meterstyle=label
text=down

[netInValue]
Meter=String
MeasureName=mNetIn
meterstyle=value
NumOfDecimals=1
Group=Values
W=40
clipstring=1
autoscale=1

[netOutLabel]
meter=string
meterstyle=label
text=up

[netOutValue]
Meter=String
MeasureName=mNetOut
meterstyle=value
NumOfDecimals=1
Group=Values
autoscale=1
W=40
clipstring=1

[endNetSeg]
meter=image
meterstyle=line
X=10R

