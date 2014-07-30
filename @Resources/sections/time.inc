; ================ Measures
[mTime]
Measure=Time
Format=%#H:%M
[mSec] 
Measure=Time 
Format=%#S
[mSecDots]
Measure=Calc
Formula=FLOOR(mSec / 10) 
MinValue=0
MaxValue=6

[Weekday]
Measure=Time
Format=%A
Substitute="Sunday":"Niedziela","Monday":"Poniedzia≥ek","Tuesday":"Wtorek","Wednesday":"åroda","Thursday":"Czwartek","Friday":"Piπtek","Saturday":"Sobota","January":"Stycznia","February":"Lutego","March":"Marca","April":"Kwietnia","May":"Maja","June":"Czerwca","July":"Lipca","August":"Sierpnia","September":"Wrzeånia","October":"Paèdziernika","November":"Listopada","December":"Grudnia"

[Month]
Measure=Time
Format=%#d %B
Substitute="Sunday":"Niedziela","Monday":"Poniedzia£ek","Tuesday":"Wtorek","Wednesday":"åroda","Thursday":"Czwartek","Friday":"Pi•tek","Saturday":"Sobota","January":"Stycznia","February":"Lutego","March":"Marca","April":"Kwietnia","May":"Maja","June":"Czerwca","July":"Lipca","August":"Sierpnia","September":"Wrzeånia","October":"Paèdziernika","November":"Listopada","December":"Grudnia"

; ================ Meters
[time]
Meter=String
MeasureName=mTime
MeterStyle=value
X=(#workareawidth#/2)
stringalign=center

[WeekdayM]
Meter=STRING
MeasureName=Weekday
MeterStyle=label
stringcase=lower
X=-20r
StringAlign=RIGHT

[MonthM]
Meter=STRING
MeasureName=Month
MeterStyle=label
stringcase=lower
X=40r
StringAlign=LEFT

[SecondsDots] 
Meter=BITMAP
MeasureName=mSecDots
X=-36r
Y=([time:Y]+[time:H])
BitmapImage=#@#images\dots2.png
BitmapFrames=6
BitmapExtend=0
SolidColor=0,0,0,1
;MouseOverAction=!Execute [!ToggleGroup Bar][!ToggleMeterGroup BgTime][!Redraw]
MouseActionCursor=0
imagetint=150,150,150
