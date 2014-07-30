; ================ Measures
[MeasureWeatherRSS]
Measure=Plugin
Plugin=Plugins\WebParser.dll
UpdateRate=3600
Url=http://weather.msn.com/RSS.aspx?wealocations=wc:#WeatherCode#&weadegreetype=#Unit#
RegExp="(?siU)<title>(.*),.*src=".*/(\d+).gif".* title="(.*)".*\. (.*)&#176;#Unit# .*src=".*/(\d+).gif".* title="(.*)".*Lo: (.*)&#176;#Unit#\..*Hi:(.*)&#176;#Unit#\..*src=".*/(\d+).gif".* title="(.*)".*Lo: (.*)&#176;#Unit#\..*Hi: (.*)&#176;#Unit#\..*src=".*/(\d+).gif".* title="(.*)".*Lo: (.*)&#176;#Unit#\..*Hi: (.*)&#176;#Unit#\."
StringIndex=1
DecodeCharacterReference=1

[MeasureWeatherTemp]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=4
DecodeCharacterReference=1
[MeasureWeatherDesc]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=3
[MeasureWeatherIcon]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=2

[MeasureWeatherTemp0]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=8
DecodeCharacterReference=1
[MeasureWeatherTempL0]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=7
DecodeCharacterReference=1
[MeasureWeatherDesc0]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=6
[MeasureWeatherIcon0]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=5

[MeasureWeatherTemp1]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=12
DecodeCharacterReference=1
[MeasureWeatherTempL1]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=11
DecodeCharacterReference=1
[MeasureWeatherDesc1]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=10
[MeasureWeatherIcon1]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=9

[MeasureWeatherTemp2]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=16
DecodeCharacterReference=1
[MeasureWeatherTempL2]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=15
DecodeCharacterReference=1
[MeasureWeatherDesc2]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=14
[MeasureWeatherIcon2]
Measure=Plugin
Plugin=Plugins\WebParser.dll
Url=[MeasureWeatherRSS]
StringIndex=13

; ================ Meters
[weather-seg]
meter=image
meterstyle=separator
X=-4r

[MeterTemp]
Meter=String
MeasureName=MeasureWeatherTemp
MeasureName2=MeasureWeatherTemp0
MeterStyle=value
X=-6r
clipstring=2
clipstringW=34
stringalign=right
postfix=" °C"
group=w.norm
ToolTipText="Tomorrow"

[MeterIcon]
Meter=IMAGE
MeasureName=MeasureWeatherIcon
X=-54r
Y=([bg:Y]+2)
H=([bg:H]-4)
W=([bg:H]-4)
antialias=1
Path=#@#images\weather\
Substitute=" ":"---"
group=w.norm

[hoverWeather]
meter=image
solidcolor=0,0,0,0
X=([weather-seg:X]-60)
Y=[bg:Y]
W=60
H=[bg:H]
;MouseOverAction=!Execute [!SetOption end-weather-seg X -68r][!ShowMeterGroup w.hov][!HideMeterGroup w.norm][!Redraw]
;MouseLeaveAction=!Execute [!SetOption end-weather-seg X -8r][!HideMeterGroup w.hov][!ShowMeterGroup w.norm][!Redraw]
MouseOverAction=!Execute [!SetOption MeterTemp Text %2][!SetOption MeterIcon MeasureName MeasureWeatherIcon0][!Redraw]
MouseLeaveAction=!Execute [!SetOption MeterTemp Text %1][!SetOption MeterIcon MeasureName MeasureWeatherIcon][!Redraw]

[end-weather-seg]
meter=image
meterstyle=line
dynamicvariables=1
X=-8r

